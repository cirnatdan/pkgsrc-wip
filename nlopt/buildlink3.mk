# $NetBSD$

BUILDLINK_TREE+=	nlopt

.if !defined(NLOPT_BUILDLINK3_MK)
NLOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nlopt+=	nlopt>=2.6.2
BUILDLINK_ABI_DEPENDS.nlopt+=	nlopt>=2.6.2
BUILDLINK_PKGSRCDIR.nlopt?=	../../wip/nlopt
.endif # NLOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-nlopt
