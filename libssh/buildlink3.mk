# $NetBSD: buildlink3.mk,v 1.1 2004/05/21 22:48:45 adrian_p Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSSH_BUILDLINK3_MK:=	${NETWIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibssh}
BUILDLINK_PACKAGES+=	libssh

.if !empty(LIBSSH_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libssh+=	libssh>=0.1
BUILDLINK_PKGSRCDIR.libssh?=	../../wip/libssh
.endif	# LIBSSH_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
