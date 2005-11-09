/* $NetBSD: hci.h,v 1.1 2005/11/09 19:00:27 plunky Exp $ */
/*
 * Copyright (c) 2005 NetBSD Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * This information originated in the Bluetooth v1.1 specification
 */

#ifndef _BLUETOOTH_HCI_H_
#define _BLUETOOTH_HCI_H_

/**************************************************************************
 **************************************************************************
 **                   Common defines and types (HCI)
 **************************************************************************
 **************************************************************************/

#define HCI_LAP_SIZE			3   /* unit LAP */
#define HCI_KEY_SIZE			16  /* link key */
#define HCI_PIN_SIZE			16  /* link PIN */
#define HCI_EVENT_MASK_SIZE		8   /* event mask */
#define HCI_CLASS_SIZE			3   /* unit class */
#define HCI_FEATURES_SIZE		8   /* LMP features */
#define HCI_UNIT_NAME_SIZE		248 /* unit name size */
#define HCI_DEVNAME_SIZE		16  /* same as dv_xname */

/* HCI specification */
#define HCI_SPEC_V10			0x00 /* v1.0 */
#define HCI_SPEC_V11			0x01 /* v1.1 */
#define HCI_SPEC_V12			0x02 /* v1.2 */
/* 0x02 - 0xFF - reserved for future use */

/* LMP features */
/* ------------------- byte 0 --------------------*/
#define HCI_LMP_3SLOT			0x01
#define HCI_LMP_5SLOT			0x02
#define HCI_LMP_ENCRYPTION		0x04
#define HCI_LMP_SLOT_OFFSET		0x08
#define HCI_LMP_TIMIACCURACY		0x10
#define HCI_LMP_SWITCH			0x20
#define HCI_LMP_HOLD_MODE		0x40
#define HCI_LMP_SNIFF_MODE		0x80
/* ------------------- byte 1 --------------------*/
#define HCI_LMP_PARK_MODE		0x01
#define HCI_LMP_RSSI			0x02
#define HCI_LMP_CHANNEL_QUALITY		0x04
#define HCI_LMP_SCO_LINK		0x08
#define HCI_LMP_HV2_PKT			0x10
#define HCI_LMP_HV3_PKT			0x20
#define HCI_LMP_ULAW_LOG		0x40
#define HCI_LMP_ALAW_LOG		0x80
/* ------------------- byte 2 --------------------*/
#define HCI_LMP_CVSD			0x01
#define HCI_LMP_PAGISCHEME		0x02
#define HCI_LMP_POWER_CONTROL		0x04
#define HCI_LMP_TRANSPARENT_SCO		0x08
#define HCI_LMP_FLOW_CONTROL_LAG0	0x10
#define HCI_LMP_FLOW_CONTROL_LAG1	0x20
#define HCI_LMP_FLOW_CONTROL_LAG2	0x40

/* Link types */
#define HCI_LINK_SCO			0x00 /* Voice */
#define HCI_LINK_ACL			0x01 /* Data */
#define HCI_LINK_eSCO			0x02 /* eSCO */
/* 0x03 - 0xFF - reserved for future use */

/* Packet types */
				/* 0x0001 - 0x0004 - reserved for future use */
#define HCI_PKT_DM1			0x0008 /* ACL link */
#define HCI_PKT_DH1			0x0010 /* ACL link */
#define HCI_PKT_HV1			0x0020 /* SCO link */
#define HCI_PKT_HV2			0x0040 /* SCO link */
#define HCI_PKT_HV3			0x0080 /* SCO link */
				/* 0x0100 - 0x0200 - reserved for future use */
#define HCI_PKT_DM3			0x0400 /* ACL link */
#define HCI_PKT_DH3			0x0800 /* ACL link */
				/* 0x1000 - 0x2000 - reserved for future use */
#define HCI_PKT_DM5			0x4000 /* ACL link */
#define HCI_PKT_DH5			0x8000 /* ACL link */

/* 
 * Connection modes/Unit modes
 *
 * This is confusing. It means that one of the units change its mode
 * for the specific connection. For example one connection was put on 
 * hold (but i could be wrong :) 
 */

#define HCI_UNIT_MODE_ACTIVE			0x00
#define HCI_UNIT_MODE_HOLD			0x01
#define HCI_UNIT_MODE_SNIFF			0x02
#define HCI_UNIT_MODE_PARK			0x03
/* 0x04 - 0xFF - reserved for future use */

/* Page scan modes */
#define HCI_MANDATORY_PAGE_SCAN_MODE		0x00
#define HCI_OPTIONAL_PAGE_SCAN_MODE1		0x01
#define HCI_OPTIONAL_PAGE_SCAN_MODE2		0x02
#define HCI_OPTIONAL_PAGE_SCAN_MODE3		0x03
/* 0x04 - 0xFF - reserved for future use */

/* Page scan repetition modes */
#define HCI_SCAN_REP_MODE0			0x00
#define HCI_SCAN_REP_MODE1			0x01
#define HCI_SCAN_REP_MODE2			0x02
/* 0x03 - 0xFF - reserved for future use */

/* Page scan period modes */
#define HCI_PAGE_SCAN_PERIOD_MODE0		0x00
#define HCI_PAGE_SCAN_PERIOD_MODE1		0x01
#define HCI_PAGE_SCAN_PERIOD_MODE2		0x02
/* 0x03 - 0xFF - reserved for future use */

/* Scan enable */
#define HCI_NO_SCAN_ENABLE			0x00
#define HCI_INQUIRY_ENABLE_PAGE_DISABLE		0x01
#define HCI_INQUIRY_DISABLE_PAGE_ENABLE		0x02
#define HCI_INQUIRY_ENABLE_PAGE_ENABLE		0x03
/* 0x04 - 0xFF - reserved for future use */

/* Hold mode activities */
#define HCI_HOLD_MODE_NO_CHANGE			0x00
#define HCI_HOLD_MODE_SUSPEND_PAGE_SCAN		0x01
#define HCI_HOLD_MODE_SUSPEND_INQUIRY_SCAN	0x02
#define HCI_HOLD_MODE_SUSPEND_PERIOD_INQUIRY	0x04
/* 0x08 - 0x80 - reserved for future use */

/* Connection roles */
#define HCI_ROLE_MASTER		 		0x00
#define HCI_ROLE_SLAVE		 		0x01
/* 0x02 - 0xFF - reserved for future use */

/* Key flags */
#define HCI_USE_SEMI_PERMANENT_LINK_KEYS	0x00
#define HCI_USE_TEMPORARY_LINK_KEY		0x01
/* 0x02 - 0xFF - reserved for future use */

/* Pin types */
#define HCI_PIN_TYPE_VARIABLE			0x00
#define HCI_PIN_TYPE_FIXED			0x01

/* Link key types */
#define HCI_LINK_KEY_TYPE_COMBINATION_KEY	0x00
#define HCI_LINK_KEY_TYPE_LOCAL_UNIT_KEY	0x01
#define HCI_LINK_KEY_TYPE_REMOTE_UNIT_KEY	0x02
/* 0x03 - 0xFF - reserved for future use */

/* Encryption modes */
#define HCI_ENCRYPTION_MODE_NONE		0x00
#define HCI_ENCRYPTION_MODE_P2P			0x01
#define HCI_ENCRYPTION_MODE_ALL			0x02
/* 0x03 - 0xFF - reserved for future use */

/* Quality of service types */
#define HCI_SERVICE_TYPE_NO_TRAFFIC		0x00
#define HCI_SERVICE_TYPE_BEST_EFFORT		0x01
#define HCI_SERVICE_TYPE_GUARANTEED		0x02
/* 0x03 - 0xFF - reserved for future use */

/* Link policy settings */
#define HCI_LINK_POLICY_DISABLE_ALL_LM_MODES	0x0000
#define HCI_LINK_POLICY_ENABLE_ROLE_SWITCH	0x0001 /* Master/Slave switch */
#define HCI_LINK_POLICY_ENABLE_HOLD_MODE	0x0002
#define HCI_LINK_POLICY_ENABLE_SNIFF_MODE	0x0004
#define HCI_LINK_POLICY_ENABLE_PARK_MODE	0x0008
/* 0x0010 - 0x8000 - reserved for future use */

/* Event masks */
#define HCI_EVMSK_ALL				0x00000000ffffffff
#define HCI_EVMSK_NONE				0x0000000000000000
#define HCI_EVMSK_INQUIRY_COMPL			0x0000000000000001
#define HCI_EVMSK_INQUIRY_RESULT		0x0000000000000002
#define HCI_EVMSK_CONN_COMPL			0x0000000000000004
#define HCI_EVMSK_CONN_REQ			0x0000000000000008
#define HCI_EVMSK_DISCON_COMPL			0x0000000000000010
#define HCI_EVMSK_AUTH_COMPL			0x0000000000000020
#define HCI_EVMSK_REMOTE_NAME_REQ_COMPL		0x0000000000000040
#define HCI_EVMSK_ENCRYPTION_CHANGE		0x0000000000000080
#define HCI_EVMSK_CHANGE_CONN_LINK_KEY_COMPL	0x0000000000000100
#define HCI_EVMSK_MASTER_LINK_KEY_COMPL		0x0000000000000200
#define HCI_EVMSK_READ_REMOTE_FEATURES_COMPL	0x0000000000000400
#define HCI_EVMSK_READ_REMOTE_VER_INFO_COMPL	0x0000000000000800
#define HCI_EVMSK_QOS_SETUP_COMPL		0x0000000000001000
#define HCI_EVMSK_COMMAND_COMPL			0x0000000000002000
#define HCI_EVMSK_COMMAND_STATUS		0x0000000000004000
#define HCI_EVMSK_HARDWARE_ERROR		0x0000000000008000
#define HCI_EVMSK_FLUSH_OCCUR			0x0000000000010000
#define HCI_EVMSK_ROLE_CHANGE			0x0000000000020000
#define HCI_EVMSK_NUM_COMPL_PKTS		0x0000000000040000
#define HCI_EVMSK_MODE_CHANGE			0x0000000000080000
#define HCI_EVMSK_RETURN_LINK_KEYS		0x0000000000100000
#define HCI_EVMSK_PIN_CODE_REQ			0x0000000000200000
#define HCI_EVMSK_LINK_KEY_REQ			0x0000000000400000
#define HCI_EVMSK_LINK_KEY_NOTIFICATION		0x0000000000800000
#define HCI_EVMSK_LOOPBACK_COMMAND		0x0000000001000000
#define HCI_EVMSK_DATA_BUFFER_OVERFLOW		0x0000000002000000
#define HCI_EVMSK_MAX_SLOT_CHANGE		0x0000000004000000
#define HCI_EVMSK_READ_CLOCK_OFFSET_COMLETE	0x0000000008000000
#define HCI_EVMSK_CONN_PKT_TYPE_CHANGED		0x0000000010000000
#define HCI_EVMSK_QOS_VIOLATION			0x0000000020000000
#define HCI_EVMSK_PAGE_SCAN_MODE_CHANGE		0x0000000040000000
#define HCI_EVMSK_PAGE_SCAN_REP_MODE_CHANGE	0x0000000080000000
/* 0x0000000100000000 - 0x8000000000000000 - reserved for future use */

/* Filter types */
#define HCI_FILTER_TYPE_NONE			0x00
#define HCI_FILTER_TYPE_INQUIRY_RESULT		0x01
#define HCI_FILTER_TYPE_CONN_SETUP		0x02
/* 0x03 - 0xFF - reserved for future use */

/* Filter condition types for HCI_FILTER_TYPE_INQUIRY_RESULT */
#define HCI_FILTER_COND_INQUIRY_NEW_UNIT	0x00
#define HCI_FILTER_COND_INQUIRY_UNIT_CLASS	0x01
#define HCI_FILTER_COND_INQUIRY_BDADDR		0x02
/* 0x03 - 0xFF - reserved for future use */

/* Filter condition types for HCI_FILTER_TYPE_CONN_SETUP */
#define HCI_FILTER_COND_CONN_ANY_UNIT		0x00
#define HCI_FILTER_COND_CONN_UNIT_CLASS		0x01
#define HCI_FILTER_COND_CONN_BDADDR		0x02
/* 0x03 - 0xFF - reserved for future use */

/* Xmit level types */
#define HCI_XMIT_LEVEL_CURRENT			0x00
#define HCI_XMIT_LEVEL_MAXIMUM			0x01
/* 0x02 - 0xFF - reserved for future use */

/* Host Controller to Host flow control */
#define HCI_HC2H_FLOW_CONTROL_NONE		0x00
#define HCI_HC2H_FLOW_CONTROL_ACL		0x01
#define HCI_HC2H_FLOW_CONTROL_SCO		0x02
#define HCI_HC2H_FLOW_CONTROL_BOTH		0x03
/* 0x04 - 0xFF - reserved future use */

/* Loopback modes */
#define HCI_LOOPBACK_NONE			0x00
#define HCI_LOOPBACK_LOCAL			0x01
#define HCI_LOOPBACK_REMOTE			0x02
/* 0x03 - 0xFF - reserved future use */

/**************************************************************************
 **************************************************************************
 **                 Link level defines, headers and types
 **************************************************************************
 **************************************************************************/

/* 
 * Macro(s) to combine OpCode and extract OGF (OpCode Group Field) 
 * and OCF (OpCode Command Field) from OpCode.
 */

#define HCI_OPCODE(gf,cf)		((((gf) & 0x3f) << 10) | ((cf) & 0x3ff))
#define HCI_OCF(op)			((op) & 0x3ff)
#define HCI_OGF(op)			(((op) >> 10) & 0x3f)

/* 
 * Marco(s) to extract/combine connection handle, BC (Broadcast) and 
 * PB (Packet boundary) flags.
 */

#define HCI_CONN_HANDLE(h)		((h) & 0x0fff)
#define HCI_PB_FLAG(h)			(((h) & 0x3000) >> 12)
#define HCI_BC_FLAG(h)			(((h) & 0xc000) >> 14)
#define HCI_MK_CONN_HANDLE(h, pb, bc) \
	(((h) & 0x0fff) | (((pb) & 3) << 12) | (((bc) & 3) << 14))

/* PB flag values */
					/* 00 - reserved for future use */
#define	HCI_PACKET_FRAGMENT		0x1 
#define	HCI_PACKET_START		0x2
					/* 11 - reserved for future use */

/* BC flag values */
#define HCI_POINT2POINT			0x0 /* only Host controller to Host */
#define HCI_BROADCAST_ACTIVE		0x1 /* both directions */
#define HCI_BROADCAST_PICONET		0x2 /* both directions */
					/* 11 - reserved for future use */

/* HCI command packet header */
typedef struct {
	u_int8_t	type;	/* MUST be 0x01 */
	u_int16_t	opcode; /* OpCode */
	u_int8_t	length; /* parameter(s) length in bytes */
} __attribute__ ((packed)) hci_cmd_hdr_t;

#define HCI_CMD_PKT			0x01
#define HCI_CMD_PKT_SIZE		(sizeof(hci_cmd_hdr_t) + 0xff)

/* ACL data packet header */
typedef struct {
	u_int8_t	type;	     /* MUST be 0x02 */
	u_int16_t	conn_handle;  /* connection handle + PB + BC flags */
	u_int16_t	length;      /* payload length in bytes */
} __attribute__ ((packed)) hci_acldata_hdr_t;

#define HCI_ACL_DATA_PKT		0x02
#define HCI_ACL_PKT_SIZE		(sizeof(hci_acldata_hdr_t) + 0xffff)

/* SCO data packet header */
typedef struct {
	u_int8_t	type;	    /* MUST be 0x03 */
	u_int16_t	conn_handle; /* connection handle + reserved bits */
	u_int8_t	length;     /* payload length in bytes */
} __attribute__ ((packed)) hci_scodata_hdr_t;

#define HCI_SCO_DATA_PKT		0x03
#define HCI_SCO_PKT_SIZE		(sizeof(hci_scodata_hdr_t) + 0xff)

/* HCI event packet header */
typedef struct {
	u_int8_t	type;	/* MUST be 0x04 */
	u_int8_t	event;  /* event */
	u_int8_t	length; /* parameter(s) length in bytes */
} __attribute__ ((packed)) hci_event_hdr_t;

#define HCI_EVENT_PKT			0x04
#define HCI_EVENT_PKT_SIZE		(sizeof(hci_event_hdr_t) + 0xff)

/* HCI status return parameter */
typedef struct {
	u_int8_t	status; /* 0x00 - success */
} __attribute__ ((packed)) hci_status_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x01	Link control commands and return parameters
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_LINK_CONTROL			0x01

#define HCI_OCF_INQUIRY					0x0001
#define HCI_CMD_INQUIRY					0x0401
typedef struct {
	u_int8_t	lap[HCI_LAP_SIZE]; /* LAP */
	u_int8_t	inquiry_length;    /* (N x 1.28) sec */
	u_int8_t	num_responses;     /* Max. # of responses before halted */
} __attribute__ ((packed)) hci_inquiry_cp;
/* No return parameter(s) */

#define HCI_OCF_INQUIRY_CANCEL				0x0002
#define HCI_CMD_INQUIRY_CANCEL				0x0402
/* No command parameter(s) */
typedef hci_status_rp	hci_inquiry_cancel_rp;

#define HCI_OCF_PERIODIC_INQUIRY			0x0003
#define HCI_CMD_PERIODIC_INQUIRY			0x0403
typedef struct {
	u_int16_t	max_period_length; /* Max. and min. amount of time */
	u_int16_t	min_period_length; /* between consecutive inquiries */
	u_int8_t	lap[HCI_LAP_SIZE]; /* LAP */
	u_int8_t	inquiry_length;    /* (inquiry_length * 1.28) sec */
	u_int8_t	num_responses;     /* Max. # of responses */
} __attribute__ ((packed)) hci_periodic_inquiry_cp;

typedef hci_status_rp	hci_periodic_inquiry_rp;
	
#define HCI_OCF_EXIT_PERIODIC_INQUIRY			0x0004
#define HCI_CMD_EXIT_PERIODIC_INQUIRY			0x0404
/* No command parameter(s) */
typedef hci_status_rp	hci_exit_periodic_inquiry_rp;

#define HCI_OCF_CREATE_CONN				0x0005
#define HCI_CMD_CREATE_CONN				0x0405
typedef struct {
	bdaddr_t	bdaddr;             /* destination address */
	u_int16_t	pkt_type;           /* packet type */
	u_int8_t	page_scan_rep_mode; /* page scan repetition mode */
	u_int8_t	page_scan_mode;     /* page scan mode */
	u_int16_t	clock_offset;       /* clock offset */
	u_int8_t	accept_role_switch; /* accept role switch? 0x00 - no */
} __attribute__ ((packed)) hci_create_conn_cp;
/* No return parameter(s) */

#define HCI_OCF_DISCONNECT				0x0006
#define HCI_CMD_DISCONNECT				0x0406
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
	u_int8_t	reason;     /* reason to disconnect */
} __attribute__ ((packed)) hci_discon_cp;
/* No return parameter(s) */

#define HCI_OCF_ADD_SCO_CONN				0x0007
#define HCI_CMD_ADD_SCO_CONN				0x0407
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	pkt_type;   /* packet type */
} __attribute__ ((packed)) hci_add_sco_conn_cp;
/* No return parameter(s) */

#define HCI_OCF_ACCEPT_CONN				0x0009
#define HCI_CMD_ACCEPT_CONN				0x0409
typedef struct {
	bdaddr_t	bdaddr; /* address of unit to be connected */
	u_int8_t	role;   /* connection role */
} __attribute__ ((packed)) hci_accept_conn_cp;
/* No return parameter(s) */

#define HCI_OCF_REJECT_CONN				0x000a
#define HCI_CMD_REJECT_CONN				0x040A
typedef struct {
	bdaddr_t	bdaddr; /* remote address */
	u_int8_t	reason; /* reason to reject */
} __attribute__ ((packed)) hci_reject_conn_cp;
/* No return parameter(s) */

#define HCI_OCF_LINK_KEY_REP				0x000b
#define HCI_CMD_LINK_KEY_REP				0x040B
typedef struct {
	bdaddr_t	bdaddr;            /* remote address */
	u_int8_t	key[HCI_KEY_SIZE]; /* key */
} __attribute__ ((packed)) hci_link_key_rep_cp;

typedef struct {
	u_int8_t	status; /* 0x00 - success */
	bdaddr_t	bdaddr; /* unit address */
} __attribute__ ((packed)) hci_link_key_rep_rp;

#define HCI_OCF_LINK_KEY_NEG_REP			0x000c
#define HCI_CMD_LINK_KEY_NEG_REP			0x040C
typedef struct {
	bdaddr_t	bdaddr; /* remote address */
} __attribute__ ((packed)) hci_link_key_neg_rep_cp;

typedef struct {
	u_int8_t	status; /* 0x00 - success */
	bdaddr_t	bdaddr; /* unit address */
} __attribute__ ((packed)) hci_link_key_neg_rep_rp;

#define HCI_OCF_PIN_CODE_REP				0x000d
#define HCI_CMD_PIN_CODE_REP				0x040D
typedef struct {
	bdaddr_t	bdaddr;               /* remote address */
	u_int8_t	pin_size;             /* pin code length (in bytes) */
	u_int8_t	pin[HCI_PIN_SIZE];    /* pin code */
} __attribute__ ((packed)) hci_pin_code_rep_cp;

typedef struct {
	u_int8_t	status; /* 0x00 - success */
	bdaddr_t	bdaddr; /* unit address */
} __attribute__ ((packed)) hci_pin_code_rep_rp;

#define HCI_OCF_PIN_CODE_NEG_REP			0x000e
#define HCI_CMD_PIN_CODE_NEG_REP			0x040E
typedef struct {
	bdaddr_t	bdaddr; /* remote address */
} __attribute__ ((packed)) hci_pin_code_neg_rep_cp;

typedef struct {
	u_int8_t	status; /* 0x00 - success */
	bdaddr_t	bdaddr; /* unit address */
} __attribute__ ((packed)) hci_pin_code_neg_rep_rp;

#define HCI_OCF_CHANGE_CONN_PACKET_TYPE			0x000f
#define HCI_CMD_CHANGE_CONN_PACKET_TYPE			0x040F
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	pkt_type;   /* packet type */
} __attribute__ ((packed)) hci_change_conn_pkt_type_cp;
/* No return parameter(s) */

#define HCI_OCF_AUTH_REQ				0x0011
#define HCI_CMD_AUTH_REQ				0x0411
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_auth_req_cp;
/* No return parameter(s) */

#define HCI_OCF_SET_CONN_ENCRYPTION			0x0013
#define HCI_CMD_SET_CONN_ENCRYPTION			0x0413
typedef struct {
	u_int16_t	conn_handle;        /* connection handle */
	u_int8_t	encryption_enable; /* 0x00 - disable, 0x01 - enable */
} __attribute__ ((packed)) hci_set_conn_encryption_cp;
/* No return parameter(s) */

#define HCI_OCF_CHANGE_CONN_LINK_KEY			0x0015
#define HCI_CMD_CHANGE_CONN_LINK_KEY			0x0415
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_change_conn_link_key_cp;
/* No return parameter(s) */

#define HCI_OCF_MASTER_LINK_KEY				0x0017
#define HCI_CMD_MASTER_LINK_KEY				0x0417
typedef struct {
	u_int8_t	key_flag; /* key flag */
} __attribute__ ((packed)) hci_master_link_key_cp;
/* No return parameter(s) */

#define HCI_OCF_REMOTE_NAME_REQ				0x0019
#define HCI_CMD_REMOTE_NAME_REQ				0x0419
typedef struct {
	bdaddr_t	bdaddr;             /* remote address */
	u_int8_t	page_scan_rep_mode; /* page scan repetition mode */
	u_int8_t	page_scan_mode;     /* page scan mode */
	u_int16_t	clock_offset;       /* clock offset */
} __attribute__ ((packed)) hci_remote_name_req_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_REMOTE_FEATURES			0x001b
#define HCI_CMD_READ_REMOTE_FEATURES			0x041B
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_read_remote_features_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_REMOTE_VER_INFO			0x001d
#define HCI_CMD_READ_REMOTE_VER_INFO			0x041D
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_read_remote_ver_info_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_CLOCK_OFFSET			0x001f
#define HCI_CMD_READ_CLOCK_OFFSET			0x041F
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_read_clock_offset_cp;
/* No return parameter(s) */

/**************************************************************************
 **************************************************************************
 ** OGF 0x02	Link policy commands and return parameters
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_LINK_POLICY			0x02

#define HCI_OCF_HOLD_MODE				0x0001
#define HCI_CMD_HOLD_MODE				0x0801
typedef struct {
	u_int16_t	conn_handle;   /* connection handle */
	u_int16_t	max_interval; /* (max_interval * 0.625) msec */
	u_int16_t	min_interval; /* (max_interval * 0.625) msec */
} __attribute__ ((packed)) hci_hold_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_SNIFF_MODE				0x0003
#define HCI_CMD_SNIFF_MODE				0x0803
typedef struct {
	u_int16_t	conn_handle;   /* connection handle */
	u_int16_t	max_interval; /* (max_interval * 0.625) msec */
	u_int16_t	min_interval; /* (max_interval * 0.625) msec */
	u_int16_t	attempt;      /* (2 * attempt - 1) * 0.625 msec */
	u_int16_t	timeout;      /* (2 * attempt - 1) * 0.625 msec */
} __attribute__ ((packed)) hci_sniff_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_EXIT_SNIFF_MODE				0x0004
#define HCI_CMD_EXIT_SNIFF_MODE				0x0804
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_exit_sniff_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_PARK_MODE				0x0005
#define HCI_CMD_PARK_MODE				0x0805
typedef struct {
	u_int16_t	conn_handle;   /* connection handle */
	u_int16_t	max_interval; /* (max_interval * 0.625) msec */
	u_int16_t	min_interval; /* (max_interval * 0.625) msec */
} __attribute__ ((packed)) hci_park_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_EXIT_PARK_MODE				0x0006
#define HCI_CMD_EXIT_PARK_MODE				0x0806
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_exit_park_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_QOS_SETUP				0x0007
#define HCI_CMD_QOS_SETUP				0x0807
typedef struct {
	u_int16_t	conn_handle;      /* connection handle */
	u_int8_t	flags;           /* reserved for future use */
	u_int8_t	service_type;    /* service type */
	u_int32_t	token_rate;      /* bytes per second */
	u_int32_t	peak_bandwidth;  /* bytes per second */
	u_int32_t	latency;         /* microseconds */
	u_int32_t	delay_variation; /* microseconds */
} __attribute__ ((packed)) hci_qos_setup_cp;
/* No return parameter(s) */

#define HCI_OCF_ROLE_DISCOVERY				0x0009
#define HCI_CMD_ROLE_DISCOVERY				0x0809
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_role_discovery_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	u_int8_t	role;       /* role for the connection handle */
} __attribute__ ((packed)) hci_role_discovery_rp;

#define HCI_OCF_SWITCH_ROLE				0x000b
#define HCI_CMD_SWITCH_ROLE				0x080B
typedef struct {
	bdaddr_t	bdaddr; /* remote address */
	u_int8_t	role;   /* new local role */
} __attribute__ ((packed)) hci_switch_role_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_LINK_POLICY_SETTINGS		0x000c
#define HCI_CMD_READ_LINK_POLICY_SETTINGS		0x080C
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_read_link_policy_settings_cp;
	
typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	settings;   /* link policy settings */
} __attribute__ ((packed)) hci_read_link_policy_settings_rp;

#define HCI_OCF_WRITE_LINK_POLICY_SETTINGS		0x000d
#define HCI_CMD_WRITE_LINK_POLICY_SETTINGS		0x080D
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	settings;   /* link policy settings */
} __attribute__ ((packed)) hci_write_link_policy_settings_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_write_link_policy_settings_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x03	Host Controller and Baseband commands and return parameters 
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_HC_BASEBAND			0x03

#define HCI_OCF_SET_EVENT_MASK				0x0001
#define HCI_CMD_SET_EVENT_MASK				0x0C01
typedef struct {
	u_int8_t	event_mask[HCI_EVENT_MASK_SIZE]; /* event_mask */
} __attribute__ ((packed)) hci_set_event_mask_cp;

typedef hci_status_rp	hci_set_event_mask_rp;

#define HCI_OCF_RESET					0x0003
#define HCI_CMD_RESET					0x0C03
/* No command parameter(s) */
typedef hci_status_rp	hci_reset_rp;

#define HCI_OCF_SET_EVENT_FILTER			0x0005
#define HCI_CMD_SET_EVENT_FILTER			0x0C05
typedef struct {
	u_int8_t	filter_type;           /* filter type */
	u_int8_t	filter_condition_type; /* filter condition type */
	u_int8_t	condition[0];          /* conditions - variable size */
} __attribute__ ((packed)) hci_set_event_filter_cp;

typedef hci_status_rp	hci_set_event_filter_rp;

#define HCI_OCF_FLUSH					0x0008
#define HCI_CMD_FLUSH					0x0C08
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_flush_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_flush_rp;

#define HCI_OCF_READ_PIN_TYPE				0x0009
#define HCI_CMD_READ_PIN_TYPE				0x0C09
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;   /* 0x00 - success */
	u_int8_t	pin_type; /* PIN type */
} __attribute__ ((packed)) hci_read_pin_type_rp;

#define HCI_OCF_WRITE_PIN_TYPE				0x000a
#define HCI_CMD_WRITE_PIN_TYPE				0x0C0A
typedef struct {
	u_int8_t	pin_type; /* PIN type */
} __attribute__ ((packed)) hci_write_pin_type_cp;

typedef hci_status_rp	hci_write_pin_type_rp;

#define HCI_OCF_CREATE_NEW_UNIT_KEY			0x000b
#define HCI_CMD_CREATE_NEW_UNIT_KEY			0x0C0B
/* No command parameter(s) */
typedef hci_status_rp	hci_create_new_unit_key_rp;

#define HCI_OCF_READ_STORED_LINK_KEY			0x000d
#define HCI_CMD_READ_STORED_LINK_KEY			0x0C0D
typedef struct {
	bdaddr_t	bdaddr;   /* address */
	u_int8_t	read_all; /* read all keys? 0x01 - yes */
} __attribute__ ((packed)) hci_read_stored_link_key_cp;

typedef struct {
	u_int8_t	status;        /* 0x00 - success */
	u_int16_t	max_num_keys;  /* Max. number of keys */
	u_int16_t	num_keys_read; /* Number of stored keys */
} __attribute__ ((packed)) hci_read_stored_link_key_rp;

#define HCI_OCF_WRITE_STORED_LINK_KEY			0x0011
#define HCI_CMD_WRITE_STORED_LINK_KEY			0x0C11
typedef struct {
	u_int8_t	num_keys_write; /* # of keys to write */
/* these are repeated "num_keys_write" times 
	bdaddr_t	bdaddr;             --- remote address(es)
	u_int8_t	key[HCI_KEY_SIZE];  --- key(s) */
} __attribute__ ((packed)) hci_write_stored_link_key_cp;

typedef struct {
	u_int8_t	status;           /* 0x00 - success */
	u_int8_t	num_keys_written; /* # of keys successfully written */
} __attribute__ ((packed)) hci_write_stored_link_key_rp;

#define HCI_OCF_DELETE_STORED_LINK_KEY			0x0012
#define HCI_CMD_DELETE_STORED_LINK_KEY			0x0C12
typedef struct {
	bdaddr_t	bdaddr;     /* address */
	u_int8_t	delete_all; /* delete all keys? 0x01 - yes */
} __attribute__ ((packed)) hci_delete_stored_link_key_cp;

typedef struct {
	u_int8_t	status;           /* 0x00 - success */
	u_int16_t	num_keys_deleted; /* Number of keys deleted */
} __attribute__ ((packed)) hci_delete_stored_link_key_rp;

#define HCI_OCF_CHANGE_LOCAL_NAME			0x0013
#define HCI_CMD_CHANGE_LOCAL_NAME			0x0C13
typedef struct {
	char		name[HCI_UNIT_NAME_SIZE]; /* new unit name */
} __attribute__ ((packed)) hci_change_local_name_cp;

typedef hci_status_rp	hci_change_local_name_rp;

#define HCI_OCF_READ_LOCAL_NAME				0x0014
#define HCI_CMD_READ_LOCAL_NAME				0x0C14
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;                   /* 0x00 - success */
	char		name[HCI_UNIT_NAME_SIZE]; /* unit name */
} __attribute__ ((packed)) hci_read_local_name_rp;

#define HCI_OCF_READ_CONN_ACCEPT_TIMEOUT		0x0015
#define HCI_CMD_READ_CONN_ACCEPT_TIMEOUT		0x0C15
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;  /* 0x00 - success */
	u_int16_t	timeout; /* (timeout * 0.625) msec */
} __attribute__ ((packed)) hci_read_conn_accept_timeout_rp;

#define HCI_OCF_WRITE_CONN_ACCEPT_TIMEOUT		0x0016
#define HCI_CMD_WRITE_CONN_ACCEPT_TIMEOUT		0x0C16
typedef struct {
	u_int16_t	timeout; /* (timeout * 0.625) msec */
} __attribute__ ((packed)) hci_write_conn_accept_timeout_cp;

typedef hci_status_rp	hci_write_conn_accept_timeout_rp;

#define HCI_OCF_READ_PAGE_TIMEOUT			0x0017
#define HCI_CMD_READ_PAGE_TIMEOUT			0x0C17
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;  /* 0x00 - success */
	u_int16_t	timeout; /* (timeout * 0.625) msec */
} __attribute__ ((packed)) hci_read_page_timeout_rp;

#define HCI_OCF_WRITE_PAGE_TIMEOUT			0x0018
#define HCI_CMD_WRITE_PAGE_TIMEOUT			0x0C18
typedef struct {
	u_int16_t	timeout; /* (timeout * 0.625) msec */
} __attribute__ ((packed)) hci_write_page_timeout_cp;

typedef hci_status_rp	hci_write_page_timeout_rp;

#define HCI_OCF_READ_SCAN_ENABLE			0x0019
#define HCI_CMD_READ_SCAN_ENABLE			0x0C19
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;      /* 0x00 - success */
	u_int8_t	scan_enable; /* Scan enable */
} __attribute__ ((packed)) hci_read_scan_enable_rp;

#define HCI_OCF_WRITE_SCAN_ENABLE			0x001a
#define HCI_CMD_WRITE_SCAN_ENABLE			0x0C1A
typedef struct {
	u_int8_t	scan_enable; /* Scan enable */
} __attribute__ ((packed)) hci_write_scan_enable_cp;

typedef hci_status_rp	hci_write_scan_enable_rp;

#define HCI_OCF_READ_PAGE_SCAN_ACTIVITY			0x001b
#define HCI_CMD_READ_PAGE_SCAN_ACTIVITY			0x0C1B
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;             /* 0x00 - success */
	u_int16_t	page_scan_interval; /* interval * 0.625 msec */
	u_int16_t	page_scan_window;   /* window * 0.625 msec */
} __attribute__ ((packed)) hci_read_page_scan_activity_rp;

#define HCI_OCF_WRITE_PAGE_SCAN_ACTIVITY		0x001c
#define HCI_CMD_WRITE_PAGE_SCAN_ACTIVITY		0x0C1C
typedef struct {
	u_int16_t	page_scan_interval; /* interval * 0.625 msec */
	u_int16_t	page_scan_window;   /* window * 0.625 msec */
} __attribute__ ((packed)) hci_write_page_scan_activity_cp;

typedef hci_status_rp	hci_write_page_scan_activity_rp;

#define HCI_OCF_READ_INQUIRY_SCAN_ACTIVITY		0x001d
#define HCI_CMD_READ_INQUIRY_SCAN_ACTIVITY		0x0C1D
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;                /* 0x00 - success */
	u_int16_t	inquiry_scan_interval; /* interval * 0.625 msec */
	u_int16_t	inquiry_scan_window;   /* window * 0.625 msec */
} __attribute__ ((packed)) hci_read_inquiry_scan_activity_rp;

#define HCI_OCF_WRITE_INQUIRY_SCAN_ACTIVITY		0x001e
#define HCI_CMD_WRITE_INQUIRY_SCAN_ACTIVITY		0x0C1E
typedef struct {
	u_int16_t	inquiry_scan_interval; /* interval * 0.625 msec */
	u_int16_t	inquiry_scan_window;   /* window * 0.625 msec */
} __attribute__ ((packed)) hci_write_inquiry_scan_activity_cp;

typedef hci_status_rp	hci_write_inquiry_scan_activity_rp;

#define HCI_OCF_READ_AUTH_ENABLE			0x001f
#define HCI_CMD_READ_AUTH_ENABLE			0x0C1F
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;      /* 0x00 - success */
	u_int8_t	auth_enable; /* 0x01 - enabled */
} __attribute__ ((packed)) hci_read_auth_enable_rp;

#define HCI_OCF_WRITE_AUTH_ENABLE			0x0020
#define HCI_CMD_WRITE_AUTH_ENABLE			0x0C20
typedef struct {
	u_int8_t	auth_enable; /* 0x01 - enabled */
} __attribute__ ((packed)) hci_write_auth_enable_cp;

typedef hci_status_rp	hci_write_auth_enable_rp;

#define HCI_OCF_READ_ENCRYPTION_MODE			0x0021
#define HCI_CMD_READ_ENCRYPTION_MODE			0x0C21
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;          /* 0x00 - success */
	u_int8_t	encryption_mode; /* encryption mode */
} __attribute__ ((packed)) hci_read_encryption_mode_rp;

#define HCI_OCF_WRITE_ENCRYPTION_MODE			0x0022
#define HCI_CMD_WRITE_ENCRYPTION_MODE			0x0C22
typedef struct {
	u_int8_t	encryption_mode; /* encryption mode */
} __attribute__ ((packed)) hci_write_encryption_mode_cp;

typedef hci_status_rp	hci_write_encryption_mode_rp;

#define HCI_OCF_READ_UNIT_CLASS				0x0023
#define HCI_CMD_READ_UNIT_CLASS				0x0C23
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;                 /* 0x00 - success */
	u_int8_t	uclass[HCI_CLASS_SIZE]; /* unit class */
} __attribute__ ((packed)) hci_read_unit_class_rp;

#define HCI_OCF_WRITE_UNIT_CLASS			0x0024
#define HCI_CMD_WRITE_UNIT_CLASS			0x0C24
typedef struct {
	u_int8_t	uclass[HCI_CLASS_SIZE]; /* unit class */
} __attribute__ ((packed)) hci_write_unit_class_cp;

typedef hci_status_rp	hci_write_unit_class_rp;

#define HCI_OCF_READ_VOICE_SETTINGS			0x0025
#define HCI_CMD_READ_VOICE_SETTINGS			0x0C25
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;   /* 0x00 - success */
	u_int16_t	settings; /* voice settings */
} __attribute__ ((packed)) hci_read_voice_settings_rp;

#define HCI_OCF_WRITE_VOICE_SETTINGS			0x0026
#define HCI_CMD_WRITE_VOICE_SETTINGS			0x0C26
typedef struct {
	u_int16_t	settings; /* voice settings */
} __attribute__ ((packed)) hci_write_voice_settings_cp;

typedef hci_status_rp	hci_write_voice_settings_rp;

#define HCI_OCF_READ_AUTO_FLUSH_TIMEOUT			0x0027
#define HCI_CMD_READ_AUTO_FLUSH_TIMEOUT			0x0C27
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_read_auto_flush_timeout_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	timeout;    /* 0x00 - no flush, timeout * 0.625 msec */
} __attribute__ ((packed)) hci_read_auto_flush_timeout_rp;
	
#define HCI_OCF_WRITE_AUTO_FLUSH_TIMEOUT		0x0028
#define HCI_CMD_WRITE_AUTO_FLUSH_TIMEOUT		0x0C28
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	timeout;    /* 0x00 - no flush, timeout * 0.625 msec */
} __attribute__ ((packed)) hci_write_auto_flush_timeout_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_write_auto_flush_timeout_rp;

#define HCI_OCF_READ_NUM_BROADCAST_RETRANS		0x0029
#define HCI_CMD_READ_NUM_BROADCAST_RETRANS		0x0C29
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;  /* 0x00 - success */
	u_int8_t	counter; /* number of broadcast retransmissions */
} __attribute__ ((packed)) hci_read_num_broadcast_retrans_rp;

#define HCI_OCF_WRITE_NUM_BROADCAST_RETRANS		0x002a
#define HCI_CMD_WRITE_NUM_BROADCAST_RETRANS		0x0C2A
typedef struct {
	u_int8_t	counter; /* number of broadcast retransmissions */
} __attribute__ ((packed)) hci_write_num_broadcast_retrans_cp;

typedef hci_status_rp	hci_write_num_broadcast_retrans_rp;

#define HCI_OCF_READ_HOLD_MODE_ACTIVITY			0x002b
#define HCI_CMD_READ_HOLD_MODE_ACTIVITY			0x0C2B
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;             /* 0x00 - success */
	u_int8_t	hold_mode_activity; /* Hold mode activities */
} __attribute__ ((packed)) hci_read_hold_mode_activity_rp;

#define HCI_OCF_WRITE_HOLD_MODE_ACTIVITY		0x002c
#define HCI_CMD_WRITE_HOLD_MODE_ACTIVITY		0x0C2C
typedef struct {
	u_int8_t	hold_mode_activity; /* Hold mode activities */
} __attribute__ ((packed)) hci_write_hold_mode_activity_cp;

typedef hci_status_rp	hci_write_hold_mode_activity_rp;

#define HCI_OCF_READ_XMIT_LEVEL				0x002d
#define HCI_CMD_READ_XMIT_LEVEL				0x0C2D
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
	u_int8_t	type;       /* Xmit level type */
} __attribute__ ((packed)) hci_read_xmit_level_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	char		level;      /* -30 <= level <= 30 dBm */
} __attribute__ ((packed)) hci_read_xmit_level_rp;

#define HCI_OCF_READ_SCO_FLOW_CONTROL			0x002e
#define HCI_CMD_READ_SCO_FLOW_CONTROL			0x0C2E
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;       /* 0x00 - success */
	u_int8_t	flow_control; /* 0x00 - disabled */
} __attribute__ ((packed)) hci_read_sco_flow_control_rp;

#define HCI_OCF_WRITE_SCO_FLOW_CONTROL			0x002f
#define HCI_CMD_WRITE_SCO_FLOW_CONTROL			0x0C2F
typedef struct {
	u_int8_t	flow_control; /* 0x00 - disabled */
} __attribute__ ((packed)) hci_write_sco_flow_control_cp;

typedef hci_status_rp	hci_write_sco_flow_control_rp;

#define HCI_OCF_HC2H_FLOW_CONTROL			0x0031
#define HCI_CMD_HC2H_FLOW_CONTROL			0x0C31
typedef struct {
	u_int8_t	hc2h_flow; /* Host Controller to Host flow control */
} __attribute__ ((packed)) hci_hc2h_flow_control_cp;

typedef hci_status_rp	hci_h2hc_flow_control_rp;

#define HCI_OCF_HOST_BUFFER_SIZE			0x0033
#define HCI_CMD_HOST_BUFFER_SIZE			0x0C33
typedef struct {
	u_int16_t	max_acl_size; /* Max. size of ACL packet (bytes) */
	u_int8_t	max_sco_size; /* Max. size of SCO packet (bytes) */
	u_int16_t	num_acl_pkts;  /* Max. number of ACL packets */
	u_int16_t	num_sco_pkts;  /* Max. number of SCO packets */
} __attribute__ ((packed)) hci_host_buffer_size_cp;

typedef hci_status_rp	hci_host_buffer_size_rp;

#define HCI_OCF_HOST_NUM_COMPL_PKTS			0x0035
#define HCI_CMD_HOST_NUM_COMPL_PKTS			0x0C35
typedef struct {
	u_int8_t	num_conn_handles; /* # of connection handles */
/* these are repeated "num_conn_handles" times
	u_int16_t	conn_handle;    --- connection handle(s)
	u_int16_t	compl_pkts;    --- # of completed packets */
} __attribute__ ((packed)) hci_host_num_compl_pkts_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_LINK_SUPERVISION_TIMEOUT		0x0036
#define HCI_CMD_READ_LINK_SUPERVISION_TIMEOUT		0x0C36
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_read_link_supervision_timeout_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	timeout;    /* Link supervision timeout * 0.625 msec */
} __attribute__ ((packed)) hci_read_link_supervision_timeout_rp;

#define HCI_OCF_WRITE_LINK_SUPERVISION_TIMEOUT		0x0037
#define HCI_CMD_WRITE_LINK_SUPERVISION_TIMEOUT		0x0C37
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	timeout;    /* Link supervision timeout * 0.625 msec */
} __attribute__ ((packed)) hci_write_link_supervision_timeout_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_write_link_supervision_timeout_rp;

#define HCI_OCF_READ_SUPPORTED_IAC_NUM			0x0038
#define HCI_CMD_READ_SUPPORTED_IAC_NUM			0x0C38
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;  /* 0x00 - success */
	u_int8_t	num_iac; /* # of supported IAC during scan */
} __attribute__ ((packed)) hci_read_supported_iac_num_rp;

#define HCI_OCF_READ_IAC_LAP				0x0039
#define HCI_CMD_READ_IAC_LAP				0x0C39
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;  /* 0x00 - success */
	u_int8_t	num_iac; /* # of IAC */
/* these are repeated "num_iac" times 
	u_int8_t	laps[HCI_LAP_SIZE]; --- LAPs */
} __attribute__ ((packed)) hci_read_iac_lap_rp;

#define HCI_OCF_WRITE_IAC_LAP				0x003a
#define HCI_CMD_WRITE_IAC_LAP				0x0C3A
typedef struct {
	u_int8_t	num_iac; /* # of IAC */
/* these are repeated "num_iac" times 
	u_int8_t	laps[HCI_LAP_SIZE]; --- LAPs */
} __attribute__ ((packed)) hci_write_iac_lap_cp;

typedef hci_status_rp	hci_write_iac_lap_rp;

#define HCI_OCF_READ_PAGE_SCAN_PERIOD			0x003b
#define HCI_CMD_READ_PAGE_SCAN_PERIOD			0x0C3B
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;                /* 0x00 - success */
	u_int8_t	page_scan_period_mode; /* Page scan period mode */
} __attribute__ ((packed)) hci_read_page_scan_period_rp;

#define HCI_OCF_WRITE_PAGE_SCAN_PERIOD			0x003c
#define HCI_CMD_WRITE_PAGE_SCAN_PERIOD			0x0C3C
typedef struct {
	u_int8_t	page_scan_period_mode; /* Page scan period mode */
} __attribute__ ((packed)) hci_write_page_scan_period_cp;

typedef hci_status_rp	hci_write_page_scan_period_rp;

#define HCI_OCF_READ_PAGE_SCAN				0x003d
#define HCI_CMD_READ_PAGE_SCAN				0x0C3D
/* No command parameter(s) */
typedef struct {
	u_int8_t	status;         /* 0x00 - success */
	u_int8_t	page_scan_mode; /* Page scan mode */
} __attribute__ ((packed)) hci_read_page_scan_rp;

#define HCI_OCF_WRITE_PAGE_SCAN				0x003e
#define HCI_CMD_WRITE_PAGE_SCAN				0x0C3E
typedef struct {
	u_int8_t	page_scan_mode; /* Page scan mode */
} __attribute__ ((packed)) hci_write_page_scan_cp;

typedef hci_status_rp	hci_write_page_scan_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x04	Informational commands and return parameters 
 ** 	     No commands in this category accept any parameters
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_INFO				0x04

#define HCI_OCF_READ_LOCAL_VER				0x0001
#define HCI_CMD_READ_LOCAL_VER				0x1001
typedef struct {
	u_int8_t	status;         /* 0x00 - success */
	u_int8_t	hci_version;    /* HCI version */
	u_int16_t	hci_revision;   /* HCI revision */
	u_int8_t	lmp_version;    /* LMP version */
	u_int16_t	manufacturer;   /* Hardware manufacturer name */
	u_int16_t	lmp_subversion; /* LMP sub-version */
} __attribute__ ((packed)) hci_read_local_ver_rp;

#define HCI_OCF_READ_LOCAL_FEATURES			0x0003
#define HCI_CMD_READ_LOCAL_FEATURES			0x1003
typedef struct {
	u_int8_t	status;                      /* 0x00 - success */
	u_int8_t	features[HCI_FEATURES_SIZE]; /* LMP features bitmsk*/
} __attribute__ ((packed)) hci_read_local_features_rp;

#define HCI_OCF_READ_BUFFER_SIZE			0x0005
#define HCI_CMD_READ_BUFFER_SIZE			0x1005
typedef struct {
	u_int8_t	status;       /* 0x00 - success */
	u_int16_t	max_acl_size; /* Max. size of ACL packet (bytes) */
	u_int8_t	max_sco_size; /* Max. size of SCO packet (bytes) */
	u_int16_t	num_acl_pkts;  /* Max. number of ACL packets */
	u_int16_t	num_sco_pkts;  /* Max. number of SCO packets */
} __attribute__ ((packed)) hci_read_buffer_size_rp;

#define HCI_OCF_READ_COUNTRY_CODE			0x0007
#define HCI_CMD_READ_COUNTRY_CODE			0x1007
typedef struct {
	u_int8_t	status;       /* 0x00 - success */
	u_int8_t	country_code; /* 0x00 - NAM, EUR, JP; 0x01 - France */
} __attribute__ ((packed)) hci_read_country_code_rp;

#define HCI_OCF_READ_BDADDR				0x0009
#define HCI_CMD_READ_BDADDR				0x1009
typedef struct {
	u_int8_t	status; /* 0x00 - success */
	bdaddr_t	bdaddr; /* unit address */
} __attribute__ ((packed)) hci_read_bdaddr_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x05	Status commands and return parameters 
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_STATUS				0x05

#define HCI_OCF_READ_FAILED_CONTACT_CNTR		0x0001
#define HCI_CMD_READ_FAILED_CONTACT_CNTR		0x1401
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_read_failed_contact_cntr_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	counter;    /* number of consecutive failed contacts */
} __attribute__ ((packed)) hci_read_failed_contact_cntr_rp;

#define HCI_OCF_RESET_FAILED_CONTACT_CNTR		0x0002
#define HCI_CMD_RESET_FAILED_CONTACT_CNTR		0x1402
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_reset_failed_contact_cntr_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_reset_failed_contact_cntr_rp;

#define HCI_OCF_GET_LINK_QUALITY			0x0003
#define HCI_CMD_GET_LINK_QUALITY			0x1403
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_get_link_quality_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	u_int8_t	quality;    /* higher value means better quality */
} __attribute__ ((packed)) hci_get_link_quality_rp;

#define HCI_OCF_READ_RSSI				0x0005
#define HCI_CMD_READ_RSSI				0x1405
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_read_rssi_cp;

typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	char		rssi;       /* -127 <= rssi <= 127 dB */
} __attribute__ ((packed)) hci_read_rssi_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x06	Testing commands and return parameters 
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_TESTING				0x06

#define HCI_OCF_READ_LOOPBACK_MODE			0x0001
#define HCI_CMD_READ_LOOPBACK_MODE			0x1801
/* No command parameter(s) */
typedef struct {
	u_int8_t	status; /* 0x00 - success */
	u_int8_t	lbmode; /* loopback mode */
} __attribute__ ((packed)) hci_read_loopback_mode_rp;

#define HCI_OCF_WRITE_LOOPBACK_MODE			0x0002
#define HCI_CMD_WRITE_LOOPBACK_MODE			0x1802
typedef struct {
	u_int8_t	lbmode; /* loopback mode */
} __attribute__ ((packed)) hci_write_loopback_mode_cp;

typedef hci_status_rp	hci_write_loopback_mode_rp;

#define HCI_OCF_ENABLE_UNIT_UNDER_TEST			0x0003
#define HCI_CMD_ENABLE_UNIT_UNDER_TEST			0x1803
/* No command parameter(s) */
typedef hci_status_rp	hci_enable_unit_under_test_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x3e	Bluetooth Logo Testing
 ** OGF 0x3f	Vendor Specific
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_BT_LOGO				0x3e	
#define HCI_OGF_VENDOR				0x3f

// Ericsson specific  FC
#define HCI_CMD_ERICSSON_WRITE_PCM_SETTINGS		0xFC07
#define HCI_CMD_ERICSSON_SET_SCO_DATA_PATH		0xFC1D


/**************************************************************************
 **************************************************************************
 **                         Events and event parameters
 **************************************************************************
 **************************************************************************/

#define HCI_EVENT_INQUIRY_COMPL			0x01
typedef struct {
	u_int8_t	status; /* 0x00 - success */
} __attribute__ ((packed)) hci_inquiry_compl_ep;

#define HCI_EVENT_INQUIRY_RESULT		0x02
typedef struct {
	u_int8_t	num_responses;      /* number of responses */
/*	hci_inquiry_response[num_responses]   -- see below */
} __attribute__ ((packed)) hci_inquiry_result_ep;

typedef struct {
	bdaddr_t	bdaddr;                   /* unit address */
	u_int8_t	page_scan_rep_mode;       /* page scan rep. mode */
	u_int8_t	page_scan_period_mode;    /* page scan period mode */
	u_int8_t	page_scan_mode;           /* page scan mode */
	u_int8_t	uclass[HCI_CLASS_SIZE];   /* unit class */
	u_int16_t	clock_offset;             /* clock offset */
} __attribute__ ((packed)) hci_inquiry_response;

#define HCI_EVENT_CONN_COMPL			0x03
typedef struct {
	u_int8_t	status;          /* 0x00 - success */
	u_int16_t	conn_handle;      /* Connection handle */
	bdaddr_t	bdaddr;          /* remote unit address */
	u_int8_t	link_type;       /* Link type */
	u_int8_t	encryption_mode; /* Encryption mode */
} __attribute__ ((packed)) hci_conn_compl_ep;

#define HCI_EVENT_CONN_REQ			0x04
typedef struct {
	bdaddr_t	bdaddr;                 /* remote unit address */
	u_int8_t	uclass[HCI_CLASS_SIZE]; /* remote unit class */
	u_int8_t	link_type;              /* link type */
} __attribute__ ((packed)) hci_conn_req_ep;

#define HCI_EVENT_DISCON_COMPL			0x05
typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	u_int8_t	reason;     /* reason to disconnect */
} __attribute__ ((packed)) hci_discon_compl_ep;

#define HCI_EVENT_AUTH_COMPL			0x06
typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_auth_compl_ep;

#define HCI_EVENT_REMOTE_NAME_REQ_COMPL		0x07
typedef struct {
	u_int8_t	status;                   /* 0x00 - success */
	bdaddr_t	bdaddr;                   /* remote unit address */
	char		name[HCI_UNIT_NAME_SIZE]; /* remote unit name */
} __attribute__ ((packed)) hci_remote_name_req_compl_ep;

#define HCI_EVENT_ENCRYPTION_CHANGE		0x08
typedef struct {
	u_int8_t	status;            /* 0x00 - success */
	u_int16_t	conn_handle;        /* Connection handle */
	u_int8_t	encryption_enable; /* 0x00 - disable */
} __attribute__ ((packed)) hci_encryption_change_ep;

#define HCI_EVENT_CHANGE_CONN_LINK_KEY_COMPL	0x09
typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* Connection handle */
} __attribute__ ((packed)) hci_change_conn_link_key_compl_ep;

#define HCI_EVENT_MASTER_LINK_KEY_COMPL		0x0a
typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* Connection handle */
	u_int8_t	key_flag;   /* Key flag */
} __attribute__ ((packed)) hci_master_link_key_compl_ep;

#define HCI_EVENT_READ_REMOTE_FEATURES_COMPL	0x0b
typedef struct {
	u_int8_t	status;                      /* 0x00 - success */
	u_int16_t	conn_handle;                  /* Connection handle */
	u_int8_t	features[HCI_FEATURES_SIZE]; /* LMP features bitmsk*/
} __attribute__ ((packed)) hci_read_remote_features_compl_ep;

#define HCI_EVENT_READ_REMOTE_VER_INFO_COMPL	0x0c
typedef struct {
	u_int8_t	status;         /* 0x00 - success */
	u_int16_t	conn_handle;     /* Connection handle */
	u_int8_t	lmp_version;    /* LMP version */
	u_int16_t	manufacturer;   /* Hardware manufacturer name */
	u_int16_t	lmp_subversion; /* LMP sub-version */
} __attribute__ ((packed)) hci_read_remote_ver_info_compl_ep;

#define HCI_EVENT_QOS_SETUP_COMPL		0x0d
typedef struct {
	u_int8_t	status;          /* 0x00 - success */
	u_int16_t	conn_handle;      /* connection handle */
	u_int8_t	flags;           /* reserved for future use */
	u_int8_t	service_type;    /* service type */
	u_int32_t	token_rate;      /* bytes per second */
	u_int32_t	peak_bandwidth;  /* bytes per second */
	u_int32_t	latency;         /* microseconds */
	u_int32_t	delay_variation; /* microseconds */
} __attribute__ ((packed)) hci_qos_setup_compl_ep;

#define HCI_EVENT_COMMAND_COMPL			0x0e
typedef struct {
	u_int8_t	num_cmd_pkts; /* # of HCI command packets */
	u_int16_t	opcode;       /* command OpCode */
	/* command return parameters (if any) */
} __attribute__ ((packed)) hci_command_compl_ep;

#define HCI_EVENT_COMMAND_STATUS		0x0f
typedef struct {
	u_int8_t	status;       /* 0x00 - pending */
	u_int8_t	num_cmd_pkts; /* # of HCI command packets */
	u_int16_t	opcode;       /* command OpCode */
} __attribute__ ((packed)) hci_command_status_ep;

#define HCI_EVENT_HARDWARE_ERROR		0x10
typedef struct {
	u_int8_t	hardware_code; /* hardware error code */
} __attribute__ ((packed)) hci_hardware_error_ep;

#define HCI_EVENT_FLUSH_OCCUR			0x11
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_flush_occur_ep;

#define HCI_EVENT_ROLE_CHANGE			0x12
typedef struct {
	u_int8_t	status; /* 0x00 - success */
	bdaddr_t	bdaddr; /* address of remote unit */
	u_int8_t	role;   /* new connection role */
} __attribute__ ((packed)) hci_role_change_ep;

#define HCI_EVENT_NUM_COMPL_PKTS		0x13
typedef struct {
	u_int8_t	num_conn_handles; /* # of connection handles */
/* these are repeated "num_conn_handles" times 
	u_int16_t	conn_handle; --- connection handle(s)
	u_int16_t	compl_pkts; --- # of completed packets */
} __attribute__ ((packed)) hci_num_compl_pkts_ep;

#define HCI_EVENT_MODE_CHANGE			0x14
typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	u_int8_t	unit_mode;  /* remote unit mode */
	u_int16_t	interval;   /* interval * 0.625 msec */
} __attribute__ ((packed)) hci_mode_change_ep;

#define HCI_EVENT_RETURN_LINK_KEYS		0x15
typedef struct {
	u_int8_t	num_keys; /* # of keys */
/* these are repeated "num_keys" times 
	bdaddr_t	bdaddr;               --- remote address(es)
	u_int8_t	key[HCI_KEY_SIZE]; --- key(s) */
} __attribute__ ((packed)) hci_return_link_keys_ep;

#define HCI_EVENT_PIN_CODE_REQ			0x16
typedef struct {
	bdaddr_t	bdaddr; /* remote unit address */
} __attribute__ ((packed)) hci_pin_code_req_ep;

#define HCI_EVENT_LINK_KEY_REQ			0x17
typedef struct {
	bdaddr_t	bdaddr; /* remote unit address */
} __attribute__ ((packed)) hci_link_key_req_ep;

#define HCI_EVENT_LINK_KEY_NOTIFICATION		0x18
typedef struct {
	bdaddr_t	bdaddr;            /* remote unit address */
	u_int8_t	key[HCI_KEY_SIZE]; /* link key */
	u_int8_t	key_type;          /* type of the key */
} __attribute__ ((packed)) hci_link_key_notification_ep;

#define HCI_EVENT_LOOPBACK_COMMAND		0x19
typedef struct {
	u_int8_t	command[0]; /* Command packet */
} __attribute__ ((packed)) hci_loopback_command_ep;

#define HCI_EVENT_DATA_BUFFER_OVERFLOW		0x1a
typedef struct {
	u_int8_t	link_type; /* Link type */
} __attribute__ ((packed)) hci_data_buffer_overflow_ep;

#define HCI_EVENT_MAX_SLOT_CHANGE		0x1b
typedef struct {
	u_int16_t	conn_handle;    /* connection handle */
	u_int8_t	lmp_max_slots; /* Max. # of slots allowed */
} __attribute__ ((packed)) hci_max_slot_change_ep;

#define HCI_EVENT_READ_CLOCK_OFFSET_COMPL	0x1c
typedef struct {
	u_int8_t	status;       /* 0x00 - success */
	u_int16_t	conn_handle;   /* Connection handle */
	u_int16_t	clock_offset; /* Clock offset */
} __attribute__ ((packed)) hci_read_clock_offset_compl_ep;

#define HCI_EVENT_CONN_PKT_TYPE_CHANGED		0x1d
typedef struct {
	u_int8_t	status;     /* 0x00 - success */
	u_int16_t	conn_handle; /* connection handle */
	u_int16_t	pkt_type;   /* packet type */
} __attribute__ ((packed)) hci_conn_pkt_type_changed_ep;

#define HCI_EVENT_QOS_VIOLATION			0x1e
typedef struct {
	u_int16_t	conn_handle; /* connection handle */
} __attribute__ ((packed)) hci_qos_violation_ep;

#define HCI_EVENT_PAGE_SCAN_MODE_CHANGE		0x1f
typedef struct {
	bdaddr_t	bdaddr;         /* destination address */
	u_int8_t	page_scan_mode; /* page scan mode */
} __attribute__ ((packed)) hci_page_scan_mode_change_ep;

#define HCI_EVENT_PAGE_SCAN_REP_MODE_CHANGE	0x20
typedef struct {
	bdaddr_t	bdaddr;             /* destination address */
	u_int8_t	page_scan_rep_mode; /* page scan repetition mode */
} __attribute__ ((packed)) hci_page_scan_rep_mode_change_ep;

#define HCI_EVENT_BT_LOGO			0xfe

#define HCI_EVENT_VENDOR			0xff

/**************************************************************************
 **************************************************************************
 **                 Socket definitions
 **************************************************************************
 **************************************************************************/

/* HCI socket options */
#define SO_HCI_EVT_FILTER		1	/* get/set event filter */
#define SO_HCI_PKT_FILTER		2	/* get/set packet filter */
#define SO_HCI_DIRECTION		3	/* packet direction indicator */

/* Control Messages */
#define SCM_HCI_DIRECTION		SO_HCI_DIRECTION

/*
 * HCI socket filter and get/set routines
 *
 * for ease of use, we filter 256 possible events/packets
 */
struct hci_filter {
	u_int32_t	mask[8];	// 256 bits
};

static inline void hci_filter_set(u_int8_t bit, struct hci_filter *filter)
{
	filter->mask[(bit - 1) >> 5] |= (1 << ((bit - 1) & 0x1f));
}

static inline void hci_filter_clr(u_int8_t bit, struct hci_filter *filter)
{
	filter->mask[(bit - 1) >> 5] &= ~(1 << ((bit - 1) & 0x1f));
}

static inline int hci_filter_test(u_int8_t bit, struct hci_filter *filter)
{
	return (filter->mask[(bit - 1) >> 5] & (1 << ((bit - 1) & 0x1f)));
}

/*
 * HCI socket ioctl's
 *
 * These are all indexed on the unit name
 */

struct bt_stats {
	u_int32_t	err_tx;
	u_int32_t	err_rx;
	u_int32_t	cmd_tx;
	u_int32_t	evt_rx;
	u_int32_t	acl_tx;
	u_int32_t	acl_rx;
	u_int32_t	sco_tx;
	u_int32_t	sco_rx;
	u_int32_t	byte_tx;
	u_int32_t	byte_rx;
};

struct btreq {
	char		btr_name[HCI_DEVNAME_SIZE];	/* device name */

	union {
	    struct {
		bdaddr_t  btri_bdaddr;			/* device bdaddr */
	    	u_int16_t btri_flags;			/* flags */
		u_int16_t btri_num_cmd;			/* # of free cmd buffers */
		u_int16_t btri_num_acl;			/* # of free ACL buffers */
		u_int16_t btri_num_sco;			/* # of free SCO buffers */
		u_int16_t btri_acl_mtu;			/* ACL mtu */
		u_int16_t btri_sco_mtu;			/* SCO mtu */
		u_int16_t btri_link_policy;		/* Link Policy */
		u_int16_t btri_packet_type;		/* Packet Type */
		u_int8_t  btri_uclass[HCI_CLASS_SIZE];	/* Device Class */
	    } btri;
	    struct bt_stats btrs;   /* unit stats */
	} btru;
};

#define btr_flags	btru.btri.btri_flags
#define btr_bdaddr	btru.btri.btri_bdaddr
#define btr_num_cmd	btru.btri.btri_num_cmd
#define btr_num_acl	btru.btri.btri_num_acl
#define btr_num_sco	btru.btri.btri_num_sco
#define btr_acl_mtu	btru.btri.btri_acl_mtu
#define btr_sco_mtu	btru.btri.btri_sco_mtu
#define btr_link_policy btru.btri.btri_link_policy
#define btr_packet_type btru.btri.btri_packet_type
#define btr_uclass	btru.btri.btri_uclass
#define btr_stats	btru.btrs

/* btr_flags */
#define BTF_UP			(1<<0)	/* unit is up */
#define BTF_RUNNING		(1<<1)	/* unit is running */
#define BTF_XMIT_CMD		(1<<2)	/* unit is transmitting CMD packets */
#define BTF_XMIT_ACL		(1<<3)	/* unit is transmitting ACL packets */
#define BTF_XMIT_SCO		(1<<4)	/* unit is transmitting SCO packets */
#define BTF_XMIT		(BTF_XMIT_CMD | BTF_XMIT_ACL | BTF_XMIT_SCO)
#define BTF_INIT_BDADDR		(1<<5)	/* waiting for bdaddr */
#define BTF_INIT_BUFFER_SIZE	(1<<6)	/* waiting for buffer size */

#define SIOCGBTINFO	_IOWR('b', 5, struct btreq)	/* get unit info */
#define SIOCNBTINFO	_IOWR('b', 6, struct btreq)	/* next unit info */
#define SIOCSBTINFO	_IOWR('b', 7, struct btreq)	/* set unit info */

#define SIOCGBTSTATS	_IOWR('b', 8, struct btreq)	/* get unit statistics */
#define SIOCZBTSTATS	_IOWR('b', 9, struct btreq)	/* zero unit statistics */

#endif /* _BLUETOOTH_HCI_H_ */
