# $Id: Makefile,v 1.233 2003/06/10 13:46:21 airhead Exp $
# $NetBSD: Makefile,v 1.233 2003/06/10 13:46:21 airhead Exp $

COMMENT=	WIP pkgsrc packages

SUBDIR+=	PPower4
SUBDIR+=	WEPCrack
SUBDIR+=	abook
SUBDIR+=	abuse_sdl
SUBDIR+=	adodb
SUBDIR+=	allegro
SUBDIR+=	amsn
SUBDIR+=	aolserver
SUBDIR+=	ap-bunzip2
SUBDIR+=	ap-frontpage
SUBDIR+=	ap-ometer
SUBDIR+=	autoproject
SUBDIR+=	bc
SUBDIR+=	billardgl
SUBDIR+=	bin86
SUBDIR+=	bugzilla
SUBDIR+=	byacc
SUBDIR+=	cdpr
SUBDIR+=	cherokee
SUBDIR+=	chksniff
SUBDIR+=	cjk-latex
SUBDIR+=	cjk-latex-chinese
SUBDIR+=	cjk-latex-japanese
SUBDIR+=	cjk-latex-korean
SUBDIR+=	cvsd
SUBDIR+=	dancer-ircd
SUBDIR+=	darkice
SUBDIR+=	devhelp
SUBDIR+=	dfbpoint
SUBDIR+=	dfbsee
SUBDIR+=	directfb
SUBDIR+=	drweb
SUBDIR+=	ed
SUBDIR+=	emirror
SUBDIR+=	ezbounce
SUBDIR+=	elvis
SUBDIR+=	elvis-x11
SUBDIR+=	fluxconf
SUBDIR+=	frontpage
SUBDIR+=	fuse
SUBDIR+=	fuse-utils
SUBDIR+=	fwbuilder
SUBDIR+=	galib
SUBDIR+=	gdrdao
SUBDIR+=	geeklog
SUBDIR+=	gimp-current
SUBDIR+=	gkrellm2
SUBDIR+=	gkrellm2-flynn
SUBDIR+=	gkrellm2-launch
SUBDIR+=	gkrellm2-leds
SUBDIR+=	gkrellm2-multiping
SUBDIR+=	gkrellm2-server
SUBDIR+=	gkrellm2-share
SUBDIR+=	gkrellm2-snmp
SUBDIR+=	gkrellm2-volume
SUBDIR+=	gkrellm2-xmms
SUBDIR+=	gmencoder
SUBDIR+=	gnomeicu
SUBDIR+=	gotmail
SUBDIR+=	grip
SUBDIR+=	gstreamer-player
SUBDIR+=	gtk-sharp
SUBDIR+=	gtk2-engines-mist
SUBDIR+=	gtk2-engines-xfce
SUBDIR+=	gtranslator
SUBDIR+=	hasciicam
SUBDIR+=	honeyd-arpd
SUBDIR+=	ht
SUBDIR+=	httrack
SUBDIR+=	ices
SUBDIR+=	icmpchat
SUBDIR+=	idesk
SUBDIR+=	idled
SUBDIR+=	ike-scan
SUBDIR+=	ilohamail
SUBDIR+=	ion-devel
SUBDIR+=	ion-dock
SUBDIR+=	jabberd
SUBDIR+=	jakarta-log4j
SUBDIR+=	jazz
SUBDIR+=	jdk-openjit
SUBDIR+=	jdk12
SUBDIR+=	jdk12-openjit
SUBDIR+=	jdk13
SUBDIR+=	jdk13-openjit
SUBDIR+=	jigdo
SUBDIR+=	jpgraph
SUBDIR+=	kapital
SUBDIR+=	kgpg
SUBDIR+=	korelib
SUBDIR+=	lde
SUBDIR+=	libdialog
SUBDIR+=	libfwbuilder
SUBDIR+=	libgsf
SUBDIR+=	libogg-nightly
SUBDIR+=	libshout
SUBDIR+=	libspectrum
SUBDIR+=	libvorbis-nightly
SUBDIR+=	libwpd
SUBDIR+=	libxfce4gui
SUBDIR+=	libxfce4mcs
SUBDIR+=	libxfce4util
SUBDIR+=	linux-modutils
SUBDIR+=	linux-nfs-utils
SUBDIR+=	liquidwar
SUBDIR+=	mailfilter
SUBDIR+=	maradns
SUBDIR+=	mcats
SUBDIR+=	mcats-iodbc
SUBDIR+=	mixer.tk
SUBDIR+=	mopac
SUBDIR+=	mtf
SUBDIR+=	multi-aterm
SUBDIR+=	muse
SUBDIR+=	mutella
SUBDIR+=	nagios-base
SUBDIR+=	nagios-plugin-ldap
SUBDIR+=	nagios-plugin-mysql
SUBDIR+=	nagios-plugin-pgsql
SUBDIR+=	nagios-plugin-snmp
SUBDIR+=	nagios-plugins
SUBDIR+=	navigatrix
SUBDIR+=	ncps
SUBDIR+=	net-tools
SUBDIR+=	netbeans-ide
SUBDIR+=	netkit-base
SUBDIR+=	newsx
SUBDIR+=	nvtv
SUBDIR+=	p5-CDDB
SUBDIR+=	p5-Chart
SUBDIR+=	p5-Compress-Bzip2
SUBDIR+=	p5-Data-TemporaryBag
SUBDIR+=	p5-File-Tail
SUBDIR+=	p5-GeoIP
SUBDIR+=	p5-HTTP-GHTTP
SUBDIR+=	p5-Net-Gnats
SUBDIR+=	p5-Net-Jabber
SUBDIR+=	p5-SWF-File
SUBDIR+=	p5-Unicode-String
SUBDIR+=	p5-XML-Stream
SUBDIR+=	p5-gtk2
SUBDIR+=	perltidy
SUBDIR+=	phplot
SUBDIR+=	pinball
SUBDIR+=	pixieplus
SUBDIR+=	poedit
SUBDIR+=	portmap
SUBDIR+=	ppp
SUBDIR+=	procps
SUBDIR+=	psh
SUBDIR+=	pts
SUBDIR+=	py-OpenGL
SUBDIR+=	py-OpenSSL
SUBDIR+=	py-PgSQL
SUBDIR+=	py-adns
SUBDIR+=	py-elementtree
SUBDIR+=	py-gnome2
SUBDIR+=	py-gnosis-utils
SUBDIR+=	py-libpcap
SUBDIR+=	py-spreadmodule
SUBDIR+=	py-twisted
SUBDIR+=	qinx
SUBDIR+=	qn-x11
SUBDIR+=	raptor
SUBDIR+=	rcorder
SUBDIR+=	rlpr
SUBDIR+=	scm
SUBDIR+=	scons
SUBDIR+=	scponly
SUBDIR+=	shoutcast
SUBDIR+=	slocate
SUBDIR+=	speedx
SUBDIR+=	srvx
SUBDIR+=	ssmtp
SUBDIR+=	strace
SUBDIR+=	streamripper
SUBDIR+=	sysklogd
SUBDIR+=	sysvinit
SUBDIR+=	tendra
SUBDIR+=	tex-foiltex
SUBDIR+=	theora-nightly
SUBDIR+=	totem
SUBDIR+=	trickle
SUBDIR+=	tsclient
SUBDIR+=	tuxtype2
SUBDIR+=	umbrello
SUBDIR+=	umix
SUBDIR+=	vcdgear
SUBDIR+=	vixie-cron
SUBDIR+=	vmac
SUBDIR+=	vmsbackup
SUBDIR+=	weewm
SUBDIR+=	windowlab
SUBDIR+=	words
SUBDIR+=	xawtv
SUBDIR+=	xevil
SUBDIR+=	xfce4
SUBDIR+=	xfce4-desktop
SUBDIR+=	xfce4-fm
SUBDIR+=	xfce4-fm-icons
SUBDIR+=	xfce4-gtk2-engines
SUBDIR+=	xfce4-iconbox
SUBDIR+=	xfce4-mcs-manager
SUBDIR+=	xfce4-mcs-plugins
SUBDIR+=	xfce4-mixer
SUBDIR+=	xfce4-panel
SUBDIR+=	xfce4-print
SUBDIR+=	xfce4-systray
SUBDIR+=	xfce4-themes
SUBDIR+=	xfce4-toys
SUBDIR+=	xfce4-trigger-launcher
SUBDIR+=	xfce4-utils
SUBDIR+=	xfce4-wm
SUBDIR+=	xfce4-wm-themes
SUBDIR+=	xml2doc
SUBDIR+=	xplore
SUBDIR+=	yafray
SUBDIR+=	zebra-pj



.include "../mk/bsd.pkg.subdir.mk"
