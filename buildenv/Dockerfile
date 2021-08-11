FROM debian:stretch

ARG BINUTILS_VERSION=2.31.1
ARG GCC_VERSION=8.2.0

RUN set -x \
	&& apt-get update \
	&& apt-get upgrade -y \
	&& apt-get install -y apt-utils \
	&& apt-get install -y wget gcc libgmp3-dev libmpfr-dev libisl-dev libcloog-isl-dev libmpc-dev texinfo bison flex make bzip2 patch build-essential nasm xorriso grub-pc-bin grub-common

RUN set -x \
	&& mkdir -p /usr/local/src \
	&& cd /usr/local/src \
	&& wget -q https://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VERSION}.tar.gz \
	&& wget -q https://ftp.gnu.org/gnu/gcc/gcc-${GCC_VERSION}/gcc-${GCC_VERSION}.tar.gz \
	&& tar zxf binutils-${BINUTILS_VERSION}.tar.gz \
	&& tar zxf gcc-${GCC_VERSION}.tar.gz \
	&& rm binutils-${BINUTILS_VERSION}.tar.gz gcc-${GCC_VERSION}.tar.gz \
	&& chown -R root:root binutils-${BINUTILS_VERSION} \
	&& chown -R root:root gcc-${GCC_VERSION} \
	&& chmod -R o-w,g+w binutils-${BINUTILS_VERSION} \
	&& chmod -R o-w,g+w gcc-${GCC_VERSION}

COPY src /usr/local/src/
COPY gcc/t-x86_64-elf /usr/local/src/gcc-${GCC_VERSION}/gcc/config/i386/
COPY gcc/config.gcc.patch /usr/local/src/gcc-${GCC_VERSION}/gcc/

RUN set -x \
	&& cd /usr/local/src \
	&& ./build-binutils.sh ${BINUTILS_VERSION} \
	&& ./build-gcc.sh ${GCC_VERSION}

CMD ["/bin/bash"]

VOLUME /root/env
WORKDIR /root/env

