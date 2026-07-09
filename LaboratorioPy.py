import os

# --- Módulo 3: Funciones ---

def registrar_turno(nombre_archivo):
    print("\n--- Registrar Turno ---")
    mascota = input("Nombre de la mascota: ")
    tipo = input("Tipo (perro/gato/otro): ").lower()
    
    print("\nTipos de servicio:")
    print("1. Consulta Médica ($15.000)")
    print("2. Vacunación ($20.000)")
    print("3. Cirugía ($100.000)")
    print("4. Peluquería / Baño")
    
    opcion_servicio = input("Seleccione el tipo de servicio (1-4): ")

    # Validaciones (Módulo 2: Condicionales)
    if not mascota or not tipo or not opcion_servicio:
        print("Error: Todos los campos son obligatorios.")
        return

    # Asignación de servicios y costos fijos
    if opcion_servicio == '1':
        servicio = "consulta"
        costo = 15000.0
    elif opcion_servicio == '2':
        servicio = "vacuna"
        costo = 20000.0
    elif opcion_servicio == '3':
        servicio = "cirugia"
        costo = 100000.0
    elif opcion_servicio == '4':
        print("\n--- Opciones de Peluquería ---")
        print("a. Corte higiénico ($8.000)")
        print("b. Corte de raza ($12.000)")
        print("c. Solo baño ($5.000)")
        op_corte = input("Elija el tipo de corte (a/b/c): ").lower()
        
        if op_corte == 'a':
            servicio = "peluqueria-higienico"
            costo = 8000.0
        elif op_corte == 'b':
            servicio = "peluqueria-raza"
            costo = 12000.0
        else:
            servicio = "peluqueria-bano"
            costo = 5000.0
    else:
        print("Opción incorrecta. Se registrará como 'consulta' por defecto.")
        servicio = "consulta"
        costo = 15000.0

    # Manejo de archivos (Módulo 4: Modo 'a' para agregar)
    try:
        with open(nombre_archivo, "a") as f:
            f.write(f"{mascota},{tipo},{servicio},{costo}\n")
        print("✅ Turno guardado correctamente.")
    except Exception as e:
        print(f"❌ Error al guardar: {e}")

def ver_turnos(nombre_archivo):
    print("\n--- Listado de Turnos ---")
    # Manejo de archivos (Módulo 4: Modo 'r' para leer)
    try:
        with open(nombre_archivo, "r") as f:
            lineas_archivo = f.readlines()
            
        # Almacenamos solo los turnos que tengan el formato correcto de 4 columnas
        lineas_validas = []
        for linea in lineas_archivo:
            if len(linea.strip().split(",")) == 4:
                lineas_validas.append(linea)
            
        if not lineas_validas:
            print("Aún no hay turnos registrados.")
            return []
            
        # Módulo 2: Recorremos la lista filtrada para que la numeración sea correlativa desde 1
        for i in range(len(lineas_validas)): 
            datos = lineas_validas[i].strip().split(",")
            print(f"Turno N° {i + 1} | Mascota: {datos[0]} | Tipo: {datos[1]} | Servicio: {datos[2]} | Costo: ${datos[3]}")
                
        return lineas_validas
    except FileNotFoundError:
        print("Aún no hay turnos registrados.")
        return []

def cancelar_turno(nombre_archivo):
    print("\n--- Cancelar un Turno ---")
    lineas = ver_turnos(nombre_archivo)
    
    if len(lineas) > 0:
        turno_a_borrar = input("\nIngrese el N° de turno que desea cancelar (o 0 para salir): ")
        
        try:
            indice = int(turno_a_borrar)
            if indice == 0:
                print("Operación cancelada.")
            elif 1 <= indice <= len(lineas):
                # Módulo 4: Modo 'w' para sobreescribir el archivo omitiendo el cancelado
                with open(nombre_archivo, 'w') as f:
                    for i in range(len(lineas)):
                        if i != (indice - 1):
                            f.write(lineas[i])
                print("✅ Turno cancelado y eliminado de los registros.")
            else:
                print("❌ Número de turno incorrecto.")
        except ValueError:
            print("❌ Debe ingresar un número válido.")

def ver_estadisticas(nombre_archivo):
    print("\n--- Estadísticas ---")
    try:
        cont_consulta = 0
        cont_vacuna = 0
        cont_cirugia = 0
        cont_peluqueria = 0
        recaudacion_total = 0.0
        
        with open(nombre_archivo, "r") as f:
            for linea in f:
                datos = linea.strip().split(",")
                if len(datos) == 4:
                    recaudacion_total += float(datos[3]) # Acumulador
                    
                    if "consulta" in linea:
                        cont_consulta += 1
                    elif "vacuna" in linea:
                        cont_vacuna += 1
                    elif "cirugia" in linea:
                        cont_cirugia += 1
                    elif "peluqueria" in linea:
                        cont_peluqueria += 1
        
        print(f"Total Consultas: {cont_consulta}")
        print(f"Total Vacunas: {cont_vacuna}")
        print(f"Total Cirugías: {cont_cirugia}")
        print(f"Total Peluquería/Baño: {cont_peluqueria}")
        print(f"Recaudación Total: ${recaudacion_total}")
    except FileNotFoundError:
        print("No hay datos para estadísticas.")

# --- Programa Principal ---

def main():
    archivo = "veterinaria.txt"
    opcion = ""
    
    # Módulo 2: Bucle while para mantener el menú activo
    while opcion != "5":
        print("\n--- SISTEMA VETERINARIA ---")
        print("1. Registrar turno")
        print("2. Ver turnos")
        print("3. Cancelar un turno")
        print("4. Ver estadísticas")
        print("5. Salir")
        opcion = input("Seleccione una opción: ")
        
        # Módulo 2: Estructura de control condicional
        if opcion == "1":
            registrar_turno(archivo)
        elif opcion == "2":
            ver_turnos(archivo)
        elif opcion == "3":
            cancelar_turno(archivo)
        elif opcion == "4":
            ver_estadisticas(archivo)
        elif opcion == "5":
            print("Saliendo del sistema...")
        else:
            print("Opción no válida, intente de nuevo.")

if __name__ == "__main__":
    main()