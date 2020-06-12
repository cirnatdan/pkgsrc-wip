# $NetBSD$

DISTNAME=	gnome-shell-3.36.3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-shell/3.36/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://wiki.gnome.org/Projects/GnomeShell
COMMENT=	Next generation GNOME shell
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes

.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../devel/at-spi2-atk/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
