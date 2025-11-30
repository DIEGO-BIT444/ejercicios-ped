Ejercicio Completo: Sistema de Gestión de Jugadores de un Videojuego Online 

Una empresa de videojuegos quiere administrar información de los jugadores registrados en un juego RPG online. 

Cada jugador tiene: 

id (int) 

nombre (string) 

nivel (int) 

clase (string) ej: "Guerrero", "Mago", "Arquero" 

poder (int)  una medida general de fuerza 

 

Requerimientos del programa 

Guardar todos los jugadores en un set<Player> ordenado por id. 

Crear un map<string, set<int>> que clasifique jugadores por clase (ej: todos los IDs de los magos). 

Crear un unordered_map<int, Player> para acceder rápidamente a los datos de un jugador por su ID. 

Generar un vector con todos los niveles para ordenarlos con sort y poder calcular estadísticas. 

Buscar si un nivel específico existe usando binary_search. 

Filtrar jugadores cuyo poder sea mayor a cierto valor. 

Mostrar el top 3 de jugadores más fuertes usando ordenamiento por poder (descendente). 

 
