
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
#include "img/descricao_centrifuga.h"
#include "img/descricao_diario.h"
#include "img/descricao_enxague.h"
#include "img/descricao_pesado.h"
#include "img/descricao_rapido.h"

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
	//MENU
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(90, 25, titulo_menu.width, titulo_menu.height, titulo_menu.data);
	ili9488_draw_pixmap(39, 100, menu_rapido.width, menu_rapido.height, menu_rapido.data);
	ili9488_draw_pixmap(131, 93, menu_diario.width, menu_diario.height, menu_diario.data);
	ili9488_draw_pixmap(216, 100, menu_pesado.width, menu_pesado.height, menu_pesado.data);
	ili9488_draw_pixmap(39, ILI9488_LCD_HEIGHT-151, menu_enxague.width, menu_enxague.height, menu_enxague.data);
	ili9488_draw_pixmap(216, ILI9488_LCD_HEIGHT-154, menu_centrifuga.width, menu_centrifuga.height, menu_centrifuga.data);
	*/
	//CICLORAPIDO
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(90, 25, titulo_iniciarrapido.width, titulo_iniciarrapido.height, titulo_iniciarrapido.data);
	ili9488_draw_pixmap(124, 100, menu_rapido.width, menu_rapido.height, menu_rapido.data);
	ili9488_draw_pixmap(27, 220, descricao_rapido.width, descricao_rapido.height, descricao_rapido.data);
	ili9488_draw_pixmap(39, ILI9488_LCD_HEIGHT-111, icone_iniciar.width, icone_iniciar.height, icone_iniciar.data);
	ili9488_draw_pixmap(216, ILI9488_LCD_HEIGHT-114, icone_cancelar.width, icone_cancelar.height, icone_cancelar.data);
	*/
	//DIARIO
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(90, 25, titulo_iniciardiario.width, titulo_iniciardiario.height, titulo_iniciardiario.data);
	ili9488_draw_pixmap(124, 100, menu_diario.width, menu_diario.height, menu_diario.data);
	ili9488_draw_pixmap(24, 220, descricao_diario.width, descricao_diario.height, descricao_diario.data);
	ili9488_draw_pixmap(39, ILI9488_LCD_HEIGHT-111, icone_iniciar.width, icone_iniciar.height, icone_iniciar.data);
	ili9488_draw_pixmap(216, ILI9488_LCD_HEIGHT-114, icone_cancelar.width, icone_cancelar.height, icone_cancelar.data);
	*/
	//PESADO
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(90, 25, titulo_iniciarpesado.width, titulo_iniciarpesado.height, titulo_iniciarpesado.data);
	ili9488_draw_pixmap(124, 100, menu_pesado.width, menu_pesado.height, menu_pesado.data);
	ili9488_draw_pixmap(21, 220, descricao_pesado.width, descricao_pesado.height, descricao_pesado.data);
	ili9488_draw_pixmap(39, ILI9488_LCD_HEIGHT-111, icone_iniciar.width, icone_iniciar.height, icone_iniciar.data);
	ili9488_draw_pixmap(216, ILI9488_LCD_HEIGHT-114, icone_cancelar.width, icone_cancelar.height, icone_cancelar.data);
	*/
	//ENXAGUE
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(90, 25, titulo_iniciarenxague.width, titulo_iniciarenxague.height, titulo_iniciarenxague.data);
	ili9488_draw_pixmap(124, 100, menu_enxague.width, menu_enxague.height, menu_enxague.data);
	ili9488_draw_pixmap(47, 220, descricao_enxague.width, descricao_enxague.height, descricao_enxague.data);
	ili9488_draw_pixmap(39, ILI9488_LCD_HEIGHT-111, icone_iniciar.width, icone_iniciar.height, icone_iniciar.data);
	ili9488_draw_pixmap(216, ILI9488_LCD_HEIGHT-114, icone_cancelar.width, icone_cancelar.height, icone_cancelar.data);
	*/
	//CENTRIFUGA
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(90, 25, titulo_iniciarcentrifuga.width, titulo_iniciarcentrifuga.height, titulo_iniciarcentrifuga.data);
	ili9488_draw_pixmap(124, 100, menu_centrifuga.width, menu_centrifuga.height, menu_centrifuga.data);
	ili9488_draw_pixmap(20, 220, descricao_centrifuga.width, descricao_centrifuga.height, descricao_centrifuga.data);
	ili9488_draw_pixmap(39, ILI9488_LCD_HEIGHT-111, icone_iniciar.width, icone_iniciar.height, icone_iniciar.data);
	ili9488_draw_pixmap(216, ILI9488_LCD_HEIGHT-114, icone_cancelar.width, icone_cancelar.height, icone_cancelar.data);
	*/
	//ANDAMENTO RAPIDO
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(108, 25, titulo_andamento.width, titulo_andamento.height, titulo_andamento.data);
	ili9488_draw_pixmap(124, 100, andamento_rapido.width, andamento_rapido.height, andamento_rapido.data);
	ili9488_draw_pixmap(79, ILI9488_LCD_HEIGHT-49 , icone_emergencia.width, icone_emergencia.height, icone_emergencia.data);
	*/
	//ANDAMENTO DIARIO
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(108, 25, titulo_andamento.width, titulo_andamento.height, titulo_andamento.data);
	ili9488_draw_pixmap(124, 100, andamento_diario.width, andamento_diario.height, andamento_diario.data);
	ili9488_draw_pixmap(79, ILI9488_LCD_HEIGHT-49 , icone_emergencia.width, icone_emergencia.height, icone_emergencia.data);
	*/
	//ANDAMENTO PESADO
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(108, 25, titulo_andamento.width, titulo_andamento.height, titulo_andamento.data);
	ili9488_draw_pixmap(124, 100, andamento_pesado.width, andamento_pesado.height, andamento_pesado.data);
	ili9488_draw_pixmap(79, ILI9488_LCD_HEIGHT-49 , icone_emergencia.width, icone_emergencia.height, icone_emergencia.data);
	*/
	//ANDAMENTO ENXAGUE
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(108, 25, titulo_andamento.width, titulo_andamento.height, titulo_andamento.data);
	ili9488_draw_pixmap(124, 100, andamento_enxague.width, andamento_enxague.height, andamento_enxague.data);
	ili9488_draw_pixmap(79, ILI9488_LCD_HEIGHT-49 , icone_emergencia.width, icone_emergencia.height, icone_emergencia.data);
	*/
	//ANDAMENTO CENTRIFUGA
	/*
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(10, 25, icone_travar.width, icone_travar.height, icone_travar.data);
	ili9488_draw_pixmap(108, 25, titulo_andamento.width, titulo_andamento.height, titulo_andamento.data);
	ili9488_draw_pixmap(124, 100, andamento_centrufuga.width, andamento_centrufuga.height, andamento_centrufuga.data);
	ili9488_draw_pixmap(79, ILI9488_LCD_HEIGHT-49 , icone_emergencia.width, icone_emergencia.height, icone_emergencia.data);
	*/
	//LOKADO
	
	ili9488_draw_pixmap(ILI9488_LCD_WIDTH-33, 25, icone_destravar.width, icone_destravar.height, icone_destravar.data);
	ili9488_draw_pixmap(10, 25, icone_destravar.width, icone_destravar.height, icone_destravar.data);
	
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
