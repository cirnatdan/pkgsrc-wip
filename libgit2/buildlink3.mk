# $NetBSD: buildlink3.mk,v 1.1 2013/01/02 18:21:18 othyro Exp $

BUILDLINK_TREE+=	libgit2

.if !defined(LIBGIT2_BUILDLINK3_MK)
LIBGIT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgit2+=	libgit2>=0.17.0
BUILDLINK_PKGSRCDIR.libgit2?=	../../wip/libgit2

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.endif	# LIBGIT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgit2
