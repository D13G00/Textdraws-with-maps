# Example
```c++
hook OnPlayerConnect(clientid){
	Textdraw::Create(clientid, 15.525568, 202.883178, "LD_SPAC:white", "Logo:1");
	Textdraw::TextSize(clientid, "Logo:1", 133.299957, 22.500007);
	Textdraw::Alignment(clientid, "Logo:1", 1);
	Textdraw::Color(clientid, "Logo:1", -5963521);
	Textdraw::Shadow(clientid, "Logo:1", 0);
	Textdraw::BackgroundColor(clientid, "Logo:1", 255);
	Textdraw::Font(clientid, "Logo:1", 4);
	Textdraw::Proportional(clientid, "Logo:1", 0);
	Textdraw::Selectable(clientid, "Logo:1", true);
	Textdraw::Show(clientid, "Logo:1");
	return 1;
}
```
# Callback
```c++
hook OnPlayerClickList(clientid, listitem, key[]){
	return 1;
}
```
# ¿Que beneficio tiene este include?
- Ahorro de memoria en el .amx por el tema de los 'MAX_PLAYERS'
- Ahorro de tiempo de compilacion.
- La identificacion del textdraw será mediante string 'const key[]', no sera mediante una ID como se hacia anteriormente.
# Nota
- Complementos necesarios
	- PawnPlus
	- y_va (YSI x5)
	- y_hooks (YSI x5)
- Reemplazar las siguientes variables y agregarlas a las suyas, esto es opcional, pero no es recomendable tener tantas variables con 'MAX_PLAYERS'
```c++
enum e_info{
	List:Textdraws,
	List:TextdrawsKeys,
	List:TextdrawsId
};
new PlayerInfo[MAX_PLAYERS][e_info];
```
