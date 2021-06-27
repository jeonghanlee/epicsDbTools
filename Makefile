# Makefile at the top of an extensions tree


TOP = $(CURDIR)
include $(TOP)/configure/CONFIG
DIRS += configure
DIRS += src
include $(TOP)/configure/RULES_TOP


