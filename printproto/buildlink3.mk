# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/29 03:52:54 jeremy-c-reed Exp $

BUILDLINK_DEPMETHOD.printproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PRINTPROTO_BUILDLINK3_MK:=	${PRINTPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	printproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nprintproto}
BUILDLINK_PACKAGES+=	printproto

.if !empty(PRINTPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.printproto+=	printproto>=1.0.3
BUILDLINK_PKGSRCDIR.printproto?=	../../wip/printproto
.endif	# PRINTPROTO_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
