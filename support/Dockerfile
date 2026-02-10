FROM debian:latest AS base

SHELL ["/bin/bash", "-c"]

RUN apt update
RUN apt install -y \
	# Base tools
	gawk \
	bzip2 \
	diffutils \
	gettext-base \
	git \
	help2man \
	libssl-dev \
	texinfo \
	mdbook \
	ninja-build \
	patch \
	python3 \
	python3-pip \
	python3-mako \
	rsync \
	sed \
	curl \
	mtools \
	# Generic build systems
	make \
	meson \
	cmake \
	# GNU toolchain
	libgmp-dev \
	libmpfr-dev \
	libmpc-dev \
	gcc \
	bison \
	flex \
	g++ \
	binutils \
	# LLVM toolchain
	llvm \
	llvm-dev \
	clang \
	lld \
	# Other build tools
	nasm \
	mold

# Install xbstrap
RUN pip3 install --break-system-packages xbstrap

# Switch to user
FROM base AS user
ARG USER=1000
RUN useradd -ms /bin/bash zinnia-buildenv -u $USER
USER zinnia-buildenv
WORKDIR /home/zinnia-buildenv

# Set a git profile for patches
RUN git config --global user.email "zinnia-buildenv@localhost" \
	&& git config --global user.name "zinnia-buildenv"

CMD ["bash"]
