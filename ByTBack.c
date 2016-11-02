int ExisteArchivo(const char* filename)
{
	char ubicacion[strlen(filename)+3];
	snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
	FILE* archivo;
	
	if ((archivo = fopen(ubicacion, "rb")) != NULL)
	{
		fclose(archivo);
		return 1;
	}
	return 0;
}

void GuardarPartida(const char* filename, int jugadores, int turno, int dim, char tablero[dim][dim])
{
	//Sumo 3 para asegurarme de que entren el "./" y el 0
	char ubicacion[strlen(filename)+3];
	snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
	FILE* archivo = fopen(ubicacion, "wb");

	// 0 = 2 players
	// 1 = CPU
	fwrite(&jugadores, sizeof(int), 1, archivo);

	// 1 = Le toca a P1
	// 2 = Le toca a P2 o CPU
	fwrite(&turno, sizeof(turno), 1, archivo);

	// Dimension del tablero
	fwrite(&dim, sizeof(dim), 1, archivo);

	// Tablero
	for (int i = 0; i < dim; ++i)
		for (int j = 0; j < dim; ++j)
		{
			fwrite(&(tablero[i][j]), sizeof(char), 1, archivo);
		}
	
	fclose(archivo);
}

int CargarPartida(char* filename, int jugadores, int turno, int dim, char tablero[dim][dim])
{
	if (!(ExisteArchivo(filename)))
	{
		return 0;
	}
	char ubicacion[strlen(filename)+3];
	snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
	FILE* archivo = fopen(ubicacion, "rb");

	fread(&jugadores, sizeof(int), 1, archivo);
	fread(&turno, sizeof(int), 1, archivo);
	fread(&dim, sizeof(int), 1, archivo);
	
	for (int i = 0; i < dim; ++i)
	{
		for (int j = 0; j < dim; ++j)
		{
			fread(&(tablero[i][j]), sizeof(char), 1, archivo);
		}
	}
	fclose(archivo);
	return 1;
}
