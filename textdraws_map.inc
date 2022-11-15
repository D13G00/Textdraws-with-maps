#define Textdraw:: td_
#define fn stock

#if !defined _PawnPlus_included
	#error PawnPlus not included.
#endif

enum e_player_textdraw{
	PlayerText:ID, Float:X__, Float:Y__, 
	Float:TextSizeX, Float:TextSizeY,
	Float:LetterSizeX, Float:LetterSizeY,
	Alignment, Color, Shadow,
	BackgroundColor, Font,
	Proportional, bool:Selectable,
	Text[256], Key[256]
};

enum e_info{
	List:Textdraws,
	List:TextdrawsKeys,
	List:TextdrawsId
};
new PlayerInfo[MAX_PLAYERS][e_info];

stock fn List: GetListKeys(clientid){
	return PlayerInfo[clientid][TextdrawsKeys];
}

stock fn List: GetTextdrawList(clientid){
	return PlayerInfo[clientid][Textdraws];
}

stock fn List: GetTextdrawID(clientid){
	return PlayerInfo[clientid][TextdrawsId];
}

stock fn Textdraw::Create(clientid, Float:x_, Float:y_, const text[], const key[]){
	new 
		TextdrawInfo[e_player_textdraw];
	if(!list_valid(PlayerInfo[clientid][Textdraws])){
		PlayerInfo[clientid][Textdraws] = list_new();
		PlayerInfo[clientid][TextdrawsKeys] = list_new();
		PlayerInfo[clientid][TextdrawsId] = list_new();
	}
	new 
		td_size = list_size(PlayerInfo[clientid][Textdraws]);
	TextdrawInfo[X__] = x_, TextdrawInfo[Y__] = y_;

	format(TextdrawInfo[Text], 256, "%s", text);
	format(TextdrawInfo[Key], 256, "%s", key);

	TextdrawInfo[ID] = CreatePlayerTextDraw(clientid, x_, y_, text);
	list_add_arr(PlayerInfo[clientid][Textdraws], TextdrawInfo, td_size);
	list_add_str(PlayerInfo[clientid][TextdrawsKeys], key, td_size);
	list_add(PlayerInfo[clientid][TextdrawsId], _:TextdrawInfo[ID], td_size);
	return 1;
}

fn Textdraw::TextSize(clientid, const key[], Float:x_, Float:y_){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		TextdrawInfo[TextSizeX] = x_;
		TextdrawInfo[TextSizeY] = y_;
		list_set_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawTextSize(clientid, TextdrawInfo[ID], x_, y_);
		return 1;
	}
	return 0;
}

fn Textdraw::Alignment(clientid, const key[], alignment){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		TextdrawInfo[Alignment] = alignment;
		list_set_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawAlignment(clientid, TextdrawInfo[ID], alignment);
		return 1;
	}
	return 0;	
}

fn Textdraw::Color(clientid, const key[], color){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		TextdrawInfo[Color] = color;
		list_set_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawColor(clientid, TextdrawInfo[ID], color);
		return 1;
	}
	return 0;
}


fn Textdraw::Shadow(clientid, const key[], shadow){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		TextdrawInfo[Shadow] = shadow;
		list_set_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawSetShadow(clientid, TextdrawInfo[ID], shadow);
		return 1;
	}
	return 0;
}

fn Textdraw::BackgroundColor(clientid, const key[], color){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		TextdrawInfo[BackgroundColor] = color;
		list_set_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawBackgroundColor(clientid, TextdrawInfo[ID], color);
		return 1;
	}
	return 0;
}

fn Textdraw::Font(clientid, const key[], font){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		TextdrawInfo[Font] = font;
		list_set_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawFont(clientid, TextdrawInfo[ID], font);
		return 1;
	}
	return 0;
}

fn Textdraw::Proportional(clientid, const key[], proportional){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		TextdrawInfo[Proportional] = proportional;
		list_set_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawSetProportional(clientid, TextdrawInfo[ID], proportional);
		return 1;
	}
	return 0;
}

fn Textdraw::Selectable(clientid, const key[], bool:selectable){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		TextdrawInfo[Selectable] = selectable;
		list_set_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawSetSelectable(clientid, TextdrawInfo[ID], selectable);
		return 1;
	}
	return 0;
}

fn Textdraw::Destroy(clientid, const key[]){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		list_remove(GetTextdrawList(clientid), index_);
		list_remove(GetListKeys(clientid), index_);
		PlayerTextDrawDestroy(clientid, TextdrawInfo[ID]);
		return 1;
	}
	return 0;
}

stock fn Textdraw::String(clientid, const key[], const string[], va_args<>){
	new out[512];
	va_format(out, sizeof out, string, va_start<3>);
	new index_ = list_find_str(
		GetListKeys(clientid), out
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawSetString(clientid, TextdrawInfo[ID], out);
		return 1;
	}
	return 0;
}

stock fn Textdraw::Show(clientid, const key[], va_args<>){
	new out[128];
	va_format(out, sizeof out, key, va_start<2>);
	new index_ = list_find_str(
		GetListKeys(clientid), out
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawShow(clientid, TextdrawInfo[ID]);
		return 1;
	}
	return 0;
}

fn Textdraw::Hide(clientid, const key[]){
	new index_ = list_find_str(
		GetListKeys(clientid), key
	);
	if(index_ != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index_, TextdrawInfo);
		PlayerTextDrawHide(clientid, TextdrawInfo[ID]);
		return 1;
	}
	return 0;
}

//OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
hook OnPlayerClickPlayerTD(clientid, PlayerText:playertextid){
	new find = -1;
	if(list_valid(GetTextdrawID(clientid))){
		find = list_find(GetTextdrawID(clientid), _:playertextid);
	}
	if(find != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), find, TextdrawInfo);
		if(TextdrawInfo[ID] == playertextid){ 
			CallLocalFunction("OnClickTextdraw", "ds", clientid, TextdrawInfo[Key]);
		}
	}
	return 1;
}

hook OnPlayerDisconnect(clientid, reason){
	if(list_valid(PlayerInfo[clientid][Textdraws]))
		list_delete(PlayerInfo[clientid][Textdraws]);
	if(list_valid(PlayerInfo[clientid][TextdrawsKeys]))
		list_delete(PlayerInfo[clientid][TextdrawsKeys]);
	if(list_valid(GetTextdrawID(clientid)))
		list_delete(GetTextdrawID(clientid));
	return 1;
}
