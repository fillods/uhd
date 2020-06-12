//
// Copyright 2019 Ettus Research, a National Instruments Brand
//
// SPDX-License-Identifier: GPL-3.0-or-later
//

#pragma once

#include <uhd/rfnoc/node.hpp>
#include <uhdlib/rfnoc/chdr_rx_data_xport.hpp>
#include <uhdlib/transport/rx_streamer_impl.hpp>
#include <atomic>
#include <string>

namespace uhd { namespace rfnoc {

/*!
 *  Extends the streamer_impl to be an rfnoc node so it can connect to the
 *  graph. Configures the streamer conversion and rate parameters with values
 *  received through property propagation.
 */
class rfnoc_rx_streamer : public node_t,
                          public transport::rx_streamer_impl<chdr_rx_data_xport>
{
    using disconnect_fn_t = std::function<void(const std::string&)>;

public:
    /*! Constructor
     *
     * \param num_ports The number of ports
     * \param stream_args Arguments to aid the construction of the streamer
     * \param disconnect_cb Callback function to disconnect the streamer when
     *                      the object is destroyed
     */
    rfnoc_rx_streamer(const size_t num_ports,
        const uhd::stream_args_t stream_args,
        disconnect_fn_t disconnect_cb);

    /*! Destructor
     */
    ~rfnoc_rx_streamer();

    /*! Returns a unique identifier string for this node. In every RFNoC graph,
     * no two nodes cannot have the same ID. Returns a string in the form of
     * "RxStreamer#0".
     *
     * \returns The unique ID as a string
     */
    std::string get_unique_id() const;

    /*! Returns the number of input ports for this block.
     *
     * \return noc_id The number of ports
     */
    size_t get_num_input_ports() const;

    /*! Returns the number of output ports for this block.
     *
     * Always returns 0 for this block.
     *
     * \return noc_id The number of ports
     */
    size_t get_num_output_ports() const;

    /*! Implementation of rx_streamer API method
     *
     * \param stream_cmd the stream command to issue
     */
    void issue_stream_cmd(const stream_cmd_t& stream_cmd);

    /*! Returns stream args provided at creation
     *
     * \return stream args provided when streamer is created
     */
    const uhd::stream_args_t& get_stream_args() const;

    /*! Check that all streamer ports are connected to blocks
     *
     * Overrides node_t to ensure there are no unconnected ports.
     *
     * \param connected_inputs A list of input ports that are connected
     * \param connected_outputs A list of output ports that are connected
     * \returns true if the block can deal with this configuration
     */
    bool check_topology(const std::vector<size_t>& connected_inputs,
        const std::vector<size_t>& connected_outputs);

    /*! Connects a channel to the streamer port
     *
     * Overrides method in rx_streamer_impl.
     *
     * \param channel The streamer channel to which to connect
     * \param xport The transport for the specified channel
     */
    void connect_channel(const size_t channel, chdr_rx_data_xport::uptr xport);

private:
    void _register_props(const size_t chan, const std::string& otw_format);

    void _handle_rx_event_action(
        const res_source_info& src, rx_event_action_info::sptr rx_event_action);
    void _handle_stream_cmd_action(
        const res_source_info& src, stream_cmd_action_info::sptr stream_cmd_action);

    void _handle_overrun();

    // Properties
    std::vector<property_t<double>> _scaling_in;
    std::vector<property_t<double>> _samp_rate_in;
    std::vector<property_t<double>> _tick_rate_in;
    std::vector<property_t<std::string>> _type_in;
    std::vector<property_t<size_t>> _mtu_in;

    // Streamer unique ID
    const std::string _unique_id;

    // Stream args provided at construction
    const uhd::stream_args_t _stream_args;

    // Callback function to disconnect
    const disconnect_fn_t _disconnect_cb;

    std::atomic<bool> _overrun_handling_mode{false};
    size_t _overrun_channel = 0;
};

}} // namespace uhd::rfnoc
