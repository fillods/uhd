//
// Copyright 2021 Ettus Research, A National Instruments Company
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//
// Module: mb_cpld_ps_regmap_utils.vh
// Description:
// The constants in this file are autogenerated by XmlParse.

//===============================================================================
// A numerically ordered list of registers and their HDL source files
//===============================================================================

  // PS_REGISTERS    : 0x0 (mb_cpld.v)
  // RECONFIG        : 0x40 (mb_cpld.v)
  // POWER_REGISTERS : 0x60 (mb_cpld.v)

//===============================================================================
// RegTypes
//===============================================================================

//===============================================================================
// Register Group MB_CPLD_PS_WINDOWS
//===============================================================================

  // PS_REGISTERS Window (from mb_cpld.v)
  localparam PS_REGISTERS = 'h0; // Window Offset
  localparam PS_REGISTERS_SIZE = 'h40;  // size in bytes

  // RECONFIG Window (from mb_cpld.v)
  localparam RECONFIG = 'h40; // Window Offset
  localparam RECONFIG_SIZE = 'h20;  // size in bytes

  // POWER_REGISTERS Window (from mb_cpld.v)
  localparam POWER_REGISTERS = 'h60; // Window Offset
  localparam POWER_REGISTERS_SIZE = 'h20;  // size in bytes

//===============================================================================
// Register Group PS_SPI_ENDPOINTS
//===============================================================================

  // Enumerated type SPI_ENDPOINT
  localparam SPI_ENDPOINT_SIZE = 8;
  localparam PS_CS_MB_CPLD         = 'h0;  // SPI_ENDPOINT:PS_CS_MB_CPLD
  localparam PS_CS_LMK32           = 'h1;  // SPI_ENDPOINT:PS_CS_LMK32
  localparam PS_CS_TPM             = 'h2;  // SPI_ENDPOINT:PS_CS_TPM
  localparam PS_CS_PHASE_DAC       = 'h3;  // SPI_ENDPOINT:PS_CS_PHASE_DAC
  localparam PS_CS_DB0_CAL_EEPROM  = 'h4;  // SPI_ENDPOINT:PS_CS_DB0_CAL_EEPROM
  localparam PS_CS_DB1_CAL_EEPROM  = 'h5;  // SPI_ENDPOINT:PS_CS_DB1_CAL_EEPROM
  localparam PS_CS_CLK_AUX_DB      = 'h6;  // SPI_ENDPOINT:PS_CS_CLK_AUX_DB
  localparam PS_CS_IDLE            = 'h7;  // SPI_ENDPOINT:PS_CS_IDLE
