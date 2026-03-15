FROM ubuntu:latest

# Dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    gfortran \
    python3 \
    libgfortran5 \
    time

# Build LAPACK from source (example files already inside the tarball)
COPY v3.12.1.tar.gz .
RUN tar -zxvf v3.12.1.tar.gz
RUN cp /lapack-3.12.1/make.inc.example /lapack-3.12.1/make.inc
RUN ulimit -s unlimited && cd /lapack-3.12.1 && make
RUN cd /lapack-3.12.1/CBLAS && make && \
    cd /lapack-3.12.1/LAPACKE && make && \
    cd /lapack-3.12.1/LAPACKE/example && make

# Copy and build benchmark
COPY benchmark.c    /lapack-3.12.1/LAPACKE/perfo/
COPY Makefile.bench /lapack-3.12.1/LAPACKE/perfo/
RUN cd /lapack-3.12.1/LAPACKE/perfo && make -f Makefile.bench

# Default: run benchmark
CMD /usr/bin/time -v /lapack-3.12.1/LAPACKE/perfo/benchmark