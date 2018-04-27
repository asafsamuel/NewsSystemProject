/******************************************
* Written By ASaf Samuel 206968380
* Copyright(C) 1/2018
*******************************************
* This program control over news reports.
* The program gets as argument a config-file
* with number of producers, the number of products
* each producer has to produce, and their queue size.
* Moreover, the last line in the file is the screen_buffer
* size. The program create the producers and make them
* generate news and fill their queue. The dispatcher
* take the news from the producers' queue, sort them
* and send them to the co-editors. The co-editors
* take the news and fill screen-manager queue.
* The screen manager take each news and print them
* to screen. All this process and actions work simultaneously
* with threads.
*
* =======================================================================
* = 	Many thanks to Elad Ben Zaken & Uri Grinberg who helped	me a	=
* =		lot with this matala - especially with the SystemBuilder,		=
* = 	threads and with the compilation. I don't think I was able to	=
* = 	finish this work without you!									=
* =======================================================================
*/

#include <iostream>
#include "SystemBuilder.h"

using namespace std;

int main(int argd, char** argv) 
{
	SystemBuilder builder;
	builder.build(argv[1]);
	builder.start();
	builder.clean();
	return 0;
}