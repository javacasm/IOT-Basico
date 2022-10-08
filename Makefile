
S1  = "IOT-básico.docx"

webIOT:
	pandoc --pdf-engine=xelatex   \
		-V papersize:a4paper    \
		--template=./LaTeX_ES.latex    \
		--reference-doc=plantilla_IOT.docx \
		-o  IOT_web.docx  \
		Cabecera_IOT.md \
		Cabecera_latex_IOT.md \
		1.0.0.IOT.md \
		1.1.Domotica.md \
		4.1.0.PlataformasIOT.md	

webESP32:
	pandoc --pdf-engine=xelatex   \
		-V papersize:a4paper    \
		--template=./LaTeX_ES.latex    \
		--reference-doc=plantilla_ESP32.docx \
		-o  ESP32_web.docx  \
		Cabecera_ESP32.md \
		Cabecera_latex_ESP32.md \
		2.0.Hardware.md \
		2.1.Kit_componentes_electrónicos.md \
		3.0.2.Programacion_Bloques.md \
		3.1.2.Instalacion_arduinoblocks.md \
		3.2.Leds.md \
		3.3.Reles.md \
		3.5.LCD.md \
		3.6.Sensores_analogicos.md \
		3.7.0.Sensores_atmosfericos.md \
		3.7.5.Termostato.md \
		3.8.Wifi.md \
		3.9.0.Web.md \
		4.4.0.MQTT.md \
		4.4.4.0.ThingSpeak.md \
		4.4.4.1.ThingSpeak_MQTT_arduinoblocks.md \
		4.4.5.Adafruit_IO_MQTT.md
	
1:
	pandoc --pdf-engine=xelatex   \
		-V papersize:a4paper    \
		--template=./LaTeX_ES.latex \
		--reference-doc=plantilla.docx \
		-o  $(S1)  \
		Cabecera.md \
		Cabecera_latex.md \
		1.0.IOT.md \
		1.1.Domotica.md \
		2.0.Hardware.md \
		2.1.Kit_componentes_electrónicos.md \
		SistemasIndustriales.md \
		3.0.2.Programacion_Bloques.md \
		3.1.2.Instalacion_arduinoblocks.md \
		3.2.Leds.md \
		3.3.Reles.md \
		3.4.LedPWM.md \
		3.5.LCD.md \
		3.6.Sensores_analogicos.md \
		3.7.0.Sensores_atmosfericos.md \
		3.7.5.Termostato.md \
		3.8.Wifi.md \
		3.9.0.Web.md \
		3.9.1.web_avanzada.md \
		3.9.2.RelesWeb.md \
		4.1.PlataformasIOT.md \
		4.2.ThingSpeak.md \
		4.4.0.MQTT.md \
		4.4.1.ThingSpeak_mqtt.md \
		4.4.2.Adafruit_IO.md \
		4.5.Adafruit_control.md \
		5.2.DomoticaCasera.md \
		5.5.Riego_automatico.md \
		6.3.3.Redes.md \
		6.3.4.Protocolos.md \
		ClienteServidor.md \
		6.3.5.Wifi.md 
