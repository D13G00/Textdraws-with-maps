#define Textdraw:: td_
#define fn

enum e_player_textdraw{
	PlayerText:ID, Float:X, Float:Y, 
	Float:TextSizeX, Float:TextSizeY,
	Alignment, Color, Shadow,
	BackgroundColor, Font,
	Proportional, bool:Selectable,
	Text[256], Key[256]
};

enum e_info{
	List:Textdraws,
	List:TextdrawsKeys
};
new PlayerInfo[MAX_PLAYERS][e_info];

fn List: GetListKeys(clientid){
	return PlayerInfo[clientid][TextdrawsKeys];
}

fn List: GetTextdrawList(clientid){
	return PlayerInfo[clientid][Textdraws];
}

fn Textdraw::Create(clientid, Float:x, Float:y, const text[], const key[]){
	new 
		TextdrawInfo[e_player_textdraw];
	if(!list_valid(PlayerInfo[clientid][Textdraws])){
		PlayerInfo[clientid][Textdraws] = list_new();
		PlayerInfo[clientid][TextdrawsKeys] = list_new();
	}
	new 
		td_size = list_size(PlayerInfo[clientid][Textdraws]);
	TextdrawInfo[X] = x, TextdrawInfo[Y] = y;

	format(TextdrawInfo[Text], 256, "%s", text);
	format(TextdrawInfo[Key], 256, "%s", key);

	TextdrawInfo[ID] = CreatePlayerTextDraw(clientid, x, y, text);
	list_add_arr(PlayerInfo[clientid][Textdraws], TextdrawInfo, td_size);
	list_add_str(PlayerInfo[clientid][TextdrawsKeys], key, td_size);

	new index = list_find_str(
		GetListKeys(clientid), key
	);
	printf("find create %d %s %s tdid %d", 
	index, key, TextdrawInfo[Key], _:TextdrawInfo[ID]);
	return 1;
}

fn Textdraw::TextSize(clientid, const key[], Float:x, Float:y){
	new index = list_find_str(
		GetListKeys(clientid), key
	);
	if(index != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		TextdrawInfo[TextSizeX] = x;
		TextdrawInfo[TextSizeY] = y;
		list_set_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		PlayerTextDrawTextSize(clientid, TextdrawInfo[ID], x, y);
		return 1;
	}
	return 0;
}

fn Textdraw::Alignment(clientid, const key[], alignment){
	new index = list_find_str(
		GetListKeys(clientid), key
	);
	if(index != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		TextdrawInfo[Alignment] = alignment;
		list_set_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		PlayerTextDrawAlignment(clientid, TextdrawInfo[ID], alignment);
		return 1;
	}
	return 0;	
}

fn Textdraw::Color(clientid, const key[], color){
	new index = list_find_str(
		GetListKeys(clientid), key
	);
	if(index != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		TextdrawInfo[Color] = color;
		list_set_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		PlayerTextDrawColor(clientid, TextdrawInfo[ID], color);
		return 1;
	}
	return 0;
}


fn Textdraw::Shadow(clientid, const key[], shadow){
	new index = list_find_str(
		GetListKeys(clientid), key
	);
	if(index != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		TextdrawInfo[Shadow] = shadow;
		list_set_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		PlayerTextDrawSetShadow(clientid, TextdrawInfo[ID], shadow);
		return 1;
	}
	return 0;
}

fn Textdraw::BackgroundColor(clientid, const key[], color){
	new index = list_find_str(
		GetListKeys(clientid), key
	);
	if(index != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		TextdrawInfo[BackgroundColor] = color;
		list_set_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		PlayerTextDrawBackgroundColor(clientid, TextdrawInfo[ID], color);
		return 1;
	}
	return 0;
}

fn Textdraw::Font(clientid, const key[], font){
	new index = list_find_str(
		GetListKeys(clientid), key
	);
	if(index != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		TextdrawInfo[Font] = font;
		list_set_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		PlayerTextDrawFont(clientid, TextdrawInfo[ID], font);
		return 1;
	}
	return 0;
}

fn Textdraw::Proportional(clientid, const key[], proportional){
	new index = list_find_str(
		GetListKeys(clientid), key
	);
	if(index != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		TextdrawInfo[Proportional] = proportional;
		list_set_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		PlayerTextDrawSetProportional(clientid, TextdrawInfo[ID], proportional);
		return 1;
	}
	return 0;
}

fn Textdraw::Selectable(clientid, const key[], bool:selectable){
	new index = list_find_str(
		GetListKeys(clientid), key
	);
	if(index != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		TextdrawInfo[Selectable] = selectable;
		list_set_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		PlayerTextDrawSetSelectable(clientid, TextdrawInfo[ID], selectable);
		return 1;
	}
	return 0;
}

fn Textdraw::Show(clientid, const key[]){
	new index = list_find_str(
		GetListKeys(clientid), key
	);
	if(index != -1){
		new TextdrawInfo[e_player_textdraw];
		list_get_arr(GetTextdrawList(clientid), index, TextdrawInfo);
		printf("find %d %s tdid %d", index, key, _:TextdrawInfo[ID]);
		PlayerTextDrawShow(clientid, TextdrawInfo[ID]);
		return 1;
	}
	return 0;
}

public OnPlayerDisconnect(clientid, reason){
	list_delete(PlayerInfo[clientid][Textdraws]);
	list_delete(PlayerInfo[clientid][TextdrawsKeys]);
	return 1;
}
