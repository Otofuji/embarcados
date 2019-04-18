
#include "asf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ioport.h"

typedef struct {
	const uint8_t *data;
	uint16_t width;
	uint16_t height;
	uint8_t dataSize;
} tImage;

#include "logo.h"
#include "img/icone_cancelar.h"
#include "img/icone_destravar.h"
#include "img/icone_emergencia.h"
#include "img/icone_iniciar.h"
#include "img/icone_travar.h"
#include "img/andamento_centrifuga.h"
#include "img/andamento_diario.h"
#include "img/andamento_enxague.h"
#include "img/andamento_pesado.h"
#include "img/andamento_rapido.h"
#include "img/iniciar_diario.h"
#include "img/iniciar_enxague.h"
#include "img/iniciar_pesado.h"
#include "img/iniciar_rapido.h"
#include "img/iniciar_centrifuga.h"
#include "img/menu_centrifuga.h"
#include "img/menu_diario.h"
#include "img/menu_enxague.h"
#include "img/menu_pesado.h"
#include "img/menu_rapido.h"
#include "img/titulo_iniciarcentrifuga.h"
#include "img/titulo_iniciardiario.h"
#include "img/titulo_andamento.h"
#include "img/titulo_iniciarenxague.h"
#include "img/titulo_menu.h"
#include "img/titulo_iniciarpesado.h"
#include "img/titulo_iniciarrapido.h"

#define STRING_EOL    "\r\n"
#define STRING_HEADER "-- SAME70 LCD DEMO --"STRING_EOL	\
	"-- "BOARD_NAME " --"STRING_EOL	\
	"-- Compiled: "__DATE__ " "__TIME__ " --"STRING_EOL

struct ili9488_opt_t g_ili9488_display_opt;

/**
}
/**
 * \brief Configure UART console.
 */


	
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate =		CONF_UART_BAUDRATE,
		.charlength =	CONF_UART_CHAR_LENGTH,
		.paritytype =	CONF_UART_PARITY,
		.stopbits =		CONF_UART_STOP_BITS,
	};

	/* Configure UART console. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}


static void configure_lcd(void){
	/* Initialize display parameter */
	g_ili9488_display_opt.ul_width = ILI9488_LCD_WIDTH;
	g_ili9488_display_opt.ul_height = ILI9488_LCD_HEIGHT;
	g_ili9488_display_opt.foreground_color = COLOR_CONVERT(COLOR_BLACK);
	g_ili9488_display_opt.background_color = COLOR_CONVERT(COLOR_BLACK);

	/* Initialize LCD */
	ili9488_init(&g_ili9488_display_opt);
	ili9488_draw_filled_rectangle(0, 0, ILI9488_LCD_WIDTH-1, ILI9488_LCD_HEIGHT-1);
	ili9488_set_foreground_color(COLOR_CONVERT(COLOR_BLACK));
	ili9488_draw_filled_rectangle(0, 0, ILI9488_LCD_WIDTH-1, 120-1);
	ili9488_draw_filled_rectangle(0, 360, ILI9488_LCD_WIDTH-1, 480-1);
	ili9488_draw_pixmap(0, 0, menu_rapido.width, menu_rapido.height, menu_rapido.data);
	
}

/**
 * \brief Main application function.
 *
 * Initialize system, UART console, network then start weather client.
 *
 * \return Program return value.
 */
int main(void)
{
	// array para escrita no LCD
	uint8_t stingLCD[256];
	
	/* Initialize the board. */
	sysclk_init();
	board_init();
	ioport_init();
	
	/* Initialize the UART console. */
	configure_console();
	printf(STRING_HEADER);

    /* Inicializa e configura o LCD */
	configure_lcd();

    /* Escreve na tela Computacao Embarcada 2018 */
	ili9488_set_foreground_color(COLOR_CONVERT(COLOR_BLACK));
	ili9488_draw_filled_rectangle(0, 300, ILI9488_LCD_WIDTH-1, 315);
	ili9488_set_foreground_color(COLOR_CONVERT(COLOR_WHITE));
	
	sprintf(stingLCD, "EMBACADOS %d", 2019);
	ili9488_draw_string(75, 300, stingLCD);

	while (1) {
	
	}
	return 0;
}
