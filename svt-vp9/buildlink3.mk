# $NetBSD$

BUILDLINK_TREE+=	svt-vp9

.if !defined(SVT_VP9_BUILDLINK3_MK)
SVT_VP9_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.svt-vp9+=	svt-vp9>=0.3.0
BUILDLINK_PKGSRCDIR.svt-vp9?=	../../wip/svt-vp9
.endif	# SVT_VP9_BUILDLINK3_MK

BUILDLINK_TREE+=	-svt-vp9
