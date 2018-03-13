#include "c_flipr_data_byte_reader.h"


/**************************
*** UUID : Info
* 0xE302 : Contient les caractéristiques de la dernière mesure
* 0xF906 : Contient les informations du device
* 0x0006 : [Temperature : 2 octets ; PH : 2 octets ; ORP : 2 octets ; Conductivité : 2 octets ; Mode : 1 octet ; Identifiant : 2 octets ; Batterie : 2 octets ]
* 0x07C1 : [Identifiant logiciel : 2 octets ; Identifiant matériel : 2 octets ]
* 0x549D : [Niveau batterie : 2 octets ]
* 0x73B4 : Mode du device (0: veille ; 1: normal)
* 0x940d : Lancer acquisition (ecrire une valeur sur 8 bits)
*
***************************/

c_flipr_data_byte_reader::c_flipr_data_byte_reader(){

}

c_flipr_data_byte_reader::~c_flipr_data_byte_reader()
{

}
