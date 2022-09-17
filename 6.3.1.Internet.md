# Internet

[Video: How Internet works](https://www.youtube.com/watch?v=7_LPdttKXPc)

![HowInternetWorks.png](./images/HowInternetWorks.png)


[The internet map](https://internet-map.net/)

![global-internet-map-2017-telegeography-Geoawesomeness-large.png](./images/global-internet-map-2017-telegeography-Geoawesomeness-large.png)

[Mapas de internet]

## DNSs

Es el servicio que permite encontrar los servidores de internet, traduciendo su nombre en la correspondiente IP

![dns-rev-1.gif](./images/dns-rev-1.gif)


### Herramienta [nslookup](https://www.lifewire.com/what-is-nslookup-817516)

Nos permite indagar en los servicios de nombres


        nslookup lifewire.com
        
Podemos usarla para ver c'omo se resuelven los servicios de correo


    nslookup
    > set Type=mx
    lifewire.com
    ......



### Herramienta [Ping](https://www.lifewire.com/ping-command-2618099)

    ping servidor



        ping -n 5 -l 1500 www.google.com
        
        
        

## Arquitectura

### Traceroute

(En windows)

        tracert servidor

(En linux)
        traceroute servidor
        
        
![Traceroute.jpg](./images/Traceroute.jpg)
        
  *  Herramientas de hacking
### Backbones, y arquitectura de Internet

![internet-backbone-map.png](./images/internet-backbone-map.png)

![Europa](./images/rb136f1.gif)

* Servidores va servicios
* Ejemplo: cómo funciona Google o Facebook
