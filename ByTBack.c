int InvalidMove(char tablero[N][N], int Fo, int Co, int Ff, int Cf)
{
	//ERROR 1		Posicion inicial invalida
	//ERROR 2		Posicion Final invalida
	//ERROR 3		Necesito botones especificos
	//ERROR 4		No vale cortar uno solo
	//ERROR 5		No es una diagonal
	//ERROR 6		Hay botones bloqueando el camino


	//Dominio Original
	if (Fo >= N || Fo < 0 || Co >= N || Co < 0)
		return 1;

	//Dominio Final
	if (Ff >= N || Ff < 0 || Cf >= N || Cf < 0)
		return 2;

	if (tablero[Fo][Co] == ' ' || tablero[Ff][Cf] == ' ')
		return 3;

	//Direccion
		//Se queda fijo
		if (Fo == Ff && Co == Cf)
			return 4;
		double my = (float)(Cf-Co);
		double mx = (float)(Ff-Fo);
		//No es diagonal
		if (mx != 0 	&& 		my != 0 	&& 		abs(my/mx) != 1)
			return 5;

	//Blocked
		int x;
		int y;
		int dx = (mx < 0)? -1 : (mx > 0);
		int dy = (my < 0)? -1 : (my > 0);
		for (x = Fo, y = Co;	x != Ff || y != Cf		;		x += dx, y += dy   )
				{
				if (tablero[Fo][Co] != tablero[x][y]   &&  tablero[x][y] != ' ')
					return 6;
				}
	return 0;
}
