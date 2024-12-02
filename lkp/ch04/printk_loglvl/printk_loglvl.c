/*
 * ch4/printk_loglvl/printk_loglvl.c
 ***************************************************************
 * This program is part of the source code released for the book
 *  "Linux Kernel Programming" 2E
 *  (c) Author: Kaiwan N Billimoria
 *  Publisher:  Packt
 *  GitHub repository:
 *  https://github.com/PacktPublishing/Linux-Kernel-Programming_2E
 *
 * From: Ch 4: Writing your First Kernel Module - LKMs Part 1
 ****************************************************************
 * Brief Description:
 * Quick test to see kernel printk's at all 8 log levels (and the pr_devel());
 * when run on a console, only those messages < current (console) log level
 * (seen as the first integer in the output of /proc/sys/kernel/printk) will
 * appear on the console device.
 *
 * For details, please refer the book, Ch 4.
 */

/* At the top of the file, before any includes */
#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/printk.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_AUTHOR("Kaiwan N Billimoria");
MODULE_DESCRIPTION("LKP2E book:ch4/printk_loglvl: printk at each kernel log level");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.2");


static int __init printk_loglvl_init(void)
{
	pr_emerg( "Hello, world @ log-level KERN_EMERG   [0]\n");
	pr_alert( "Hello, world @ log-level KERN_ALERT   [1]\n");
	pr_crit(  "Hello, world @ log-level KERN_CRIT    [2]\n");
	pr_err(   "Hello, world @ log-level KERN_ERR     [3]\n");
	pr_warn(  "Hello, world @ log-level KERN_WARNING [4]\n");
	pr_notice("Hello, world @ log-level KERN_NOTICE  [5]\n");
	pr_info(  "Hello, world @ log-level KERN_INFO    [6]\n");
	pr_debug( "Hello, world @ log-level KERN_DEBUG   [7]\n");
	pr_devel( "Hello, world via the pr_devel() macro"
		" (eff @KERN_DEBUG) [7]\n");

	return 0; /* success */
}

static void __exit printk_loglvl_exit(void)
{
    pr_info("Goodby, world @ log-level KERN_INFO    [6]\n");
}
module_init(printk_loglvl_init);
module_exit(printk_loglvl_exit);
