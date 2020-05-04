# $NetBSD$

BUILDLINK_TREE+=	SSVLuaWrapper

.if !defined(SSVLUAWRAPPER_BUILDLINK3_MK)
SSVLUAWRAPPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SSVLuaWrapper+=	SSVLuaWrapper>=20130708
BUILDLINK_PKGSRCDIR.SSVLuaWrapper?=	../../wip/SSVLuaWrapper

BUILDLINK_DEPMETHOD.SSVLuaWrapper?=	build
BUILDLINK_FILES.SSVLuaWrapper+=		lib/cmake/FindSSVLuaWrapper.cmake

LUA_VERSIONS_ACCEPTED=	51
.include <../../lang/lua/buildlink3.mk>

.endif	# SSVLUAWRAPPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-SSVLuaWrapper