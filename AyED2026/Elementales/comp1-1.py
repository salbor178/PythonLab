# La Mutual del personal del Banco, a pedido de un socio, canjea un plazo fijo pagándole el capital inicial.
# Luego, al cobrarse el plazo fijo, se pagan los intereses, descontando los días correspondientes y $5 por gastos.
# Se desea liquidar la diferencia entre el capital inicial y el capital con intereses,
# sabiendo que el interés es del 5% a 30 días.

def plazo_fijo():
    # Interés diario (5% / 30 días)
    intx_dia = 0.05 / 30

    # Entrada de datos
    cap_ini = float(input("Ingrese el monto del capital inicial: $"))
    dias_ant = int(input("Ingrese la cantidad de días anticipados: "))

    # Cálculo de la liquidación
    liqui = (cap_ini * 1.05) - cap_ini - (cap_ini * dias_ant * intx_dia) - 5

    # Resultado
    print(f"\nSe le debe abonar al cliente la suma de: ${liqui:.2f}")

# Ejecutar la función
plazo_fijo()
