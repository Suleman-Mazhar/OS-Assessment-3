#Full solid docker file for lapack-3.12.1

FROM ubuntu:latest

COPY v3.12.1.tar.gz .

RUN apt-get update && apt-get install -y \
        build-essential \
        gfortran \
        python3


RUN tar -zxvf v3.12.1.tar.gz
RUN cp /lapack-3.12.1/make.inc.example /lapack-3.12.1/make.inc
RUN ulimit -s unlimited && cd /lapack-3.12.1 && make


RUN cd /lapack-3.12.1/CBLAS && make && cd /lapack-3.12.1/LAPACKE && make && cd /lapack-3.12.1/LAPACKE/example && make


RUN mkdir /lapack-3.12.1/LAPACKE/myex

COPY lp_ex1.c /lapack-3.12.1/LAPACKE/myex
COPY Makefile /lapack-3.12.1/LAPACKE/myex

RUN cd /lapack-3.12.1/LAPACKE/myex && make

CMD /lapack-3.12.1/LAPACKE/myex/lp_ex1