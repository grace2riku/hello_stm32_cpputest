/**
 * @file usrcmd.c
 * @author CuBeatSystems
 * @author Shinichiro Nakamura
 * @copyright
 * ===============================================================
 * Natural Tiny Shell (NT-Shell) Version 0.3.1
 * ===============================================================
 * Copyright (c) 2010-2016 Shinichiro Nakamura
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "ntopt.h"
#include "ntlibc.h"

#include <stdio.h>
#include "main.h"
#include "CppUTest/CommandLineTestRunner.h"

#define uart_puts printf

typedef int (*USRCMDFUNC)(int argc, char **argv);

static int usrcmd_ntopt_callback(int argc, char **argv, void *extobj);
static int usrcmd_help(int argc, char **argv);
static int usrcmd_info(int argc, char **argv);
static int usrcmd_read_userbutton_b1(int argc, char **argv);
static int usrcmd_write_led_ld2(int argc, char **argv);
static int usrcmd_cpputest(int argc, char **argv);

typedef struct {
    const char* cmd;
    const char* desc;
    USRCMDFUNC func;
} cmd_table_t;

static const cmd_table_t cmdlist[] = {
    { "help", "This is a description text string for help command.", usrcmd_help },
    { "info", "This is a description text string for info command.", usrcmd_info },
    { "read_userbutton", "User button B1 reads.", usrcmd_read_userbutton_b1 },
    { "write_led", "Write to LED LD2.", usrcmd_write_led_ld2 },
    { "cpputest", "Exec CppUTest.", usrcmd_cpputest },
};

enum {
  COMMAND_HELP,
  COMMAND_INFO,
  COMMAND_READ_USER_BUTTON,
  COMMAND_WRITE_LED,
  COMMAND_CPPUTEST,
  COMMAND_MAX
};


int usrcmd_execute(const char *text)
{
    return ntopt_parse(text, usrcmd_ntopt_callback, 0);
}

static int usrcmd_ntopt_callback(int argc, char **argv, void *extobj)
{
    if (argc == 0) {
        return 0;
    }
    const cmd_table_t *p = &cmdlist[0];
    for (unsigned int i = 0; i < sizeof(cmdlist) / sizeof(cmdlist[0]); i++) {
        if (ntlibc_strcmp((const char *)argv[0], p->cmd) == 0) {
            return p->func(argc, argv);
        }
        p++;
    }
    uart_puts("Unknown command found.\r\n");
    return 0;
}

static int usrcmd_help(int argc, char **argv)
{
    const cmd_table_t *p = &cmdlist[0];
    for (unsigned int i = 0; i < sizeof(cmdlist) / sizeof(cmdlist[0]); i++) {
        uart_puts(p->cmd);
        uart_puts("\t:");
        uart_puts(p->desc);
        uart_puts("\r\n");
        p++;
    }
    return 0;
}

static int usrcmd_info(int argc, char **argv)
{
    if (argc != 2) {
        uart_puts("info sys\r\n");
        uart_puts("info ver\r\n");
        return 0;
    }
    if (ntlibc_strcmp(argv[1], "sys") == 0) {
        uart_puts("ST NUCLEO-F446RE Monitor\r\n");
        return 0;
    }
    if (ntlibc_strcmp(argv[1], "ver") == 0) {
        uart_puts("Version 0.0.0\r\n");
        return 0;
    }
    uart_puts("Unknown sub command found\r\n");
    return -1;
}

static int usrcmd_read_userbutton_b1(int argc, char **argv){
    if (argc != 1) {
        uart_puts("read_userbutton\r\n");
        return -1;
    }
	GPIO_PinState b1_pin = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	uart_puts("USER BUTTON B1 = %d\r\n", b1_pin);

	return 0;
}

static int usrcmd_write_led_ld2(int argc, char **argv){
    if (argc != 2) {
        uart_puts("write_led_ld2 1 or write_led_ld2 0\r\n");
        return -1;
    }
    GPIO_PinState PinState = GPIO_PIN_RESET;

    if (ntlibc_strcmp(argv[1], "1") == 0) PinState = GPIO_PIN_SET;
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, PinState);

	return 0;
}

static int usrcmd_cpputest(int argc, char **argv){
	CommandLineTestRunner::RunAllTests(argc, argv);
	return 0;
}
