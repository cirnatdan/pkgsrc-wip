# $NetBSD$

PKGNAME=		scummvm-bass-0
CATEGORIES=		games
#ftp can't deal with lack of urlencoded spaces on the 301
#MASTER_SITES=		http://www.scummvm.org/frs/extras/Beneath%20a%20Steel%20Sky/
MASTER_SITES=		https://fr1.eu.scummvm.net/extras/Beneath%20a%20Steel%20Sky/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.scummvm.org/games/
COMMENT=		Beneath a Steel Sky
#LICENSE=		freeware license specified in readme.txt


BASSDIR=	${PREFIX}/share/games/bass

INSTALLATION_DIRS=	bin

do-build:
	${SED} "s|@BASSDIR@|${BASSDIR}|" <${FILESDIR}/bass.sh \
		>${WRKDIR}/bass.sh

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
