#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "cJSON.h"

int main()
{
    char *json_string = "{ \
        \"faturamento_diario\": [ \
            100.5, 200.75, 0.0, 150.0, 0.0, \
            300.25, 0.0, 400.1, 0.0, 500.5, \
            600.0, 0.0, 700.75, 0.0, 800.25, \
            900.1, 1000.0, 1100.5, 0.0, 1200.25, \
            1300.0, 0.0, 1400.75, 0.0, 1500.1, \
            1600.0, 1700.5, 0.0, 1800.25, 1900.0 \
        ] \
    }";

    // Parse the JSON string
    cJSON *json = cJSON_Parse(json_string);
    if (json == NULL)
    {
        printf("Erro ao processar o JSON.\n");
        return 1;
    }

    // Get the "faturamento_diario" array
    cJSON *faturamento_array = cJSON_GetObjectItem(json, "faturamento_diario");
    if (faturamento_array == NULL || !cJSON_IsArray(faturamento_array))
    {
        printf("Erro ao obter o array de faturamento.\n");
        cJSON_Delete(json);
        return 1;
    }

    double menor_valor = DBL_MAX, maior_valor = DBL_MIN, soma = 0.0;
    int dias_com_faturamento = 0, dias_acima_media = 0;

    // Process each value in the "faturamento_diario" array
    int array_size = cJSON_GetArraySize(faturamento_array);
    for (int i = 0; i < array_size; i++)
    {
        cJSON *valor_json = cJSON_GetArrayItem(faturamento_array, i);
        if (valor_json == NULL || !cJSON_IsNumber(valor_json))
        {
            continue;
        }

        double valor = valor_json->valuedouble;
        if (valor > 0)
        {
            if (valor < menor_valor)
                menor_valor = valor;
            if (valor > maior_valor)
                maior_valor = valor;
            soma += valor;
            dias_com_faturamento++;
        }
    }

    if (dias_com_faturamento == 0)
    {
        printf("Nenhum dia com faturamento para calcular a média.\n");
        cJSON_Delete(json);
        return 1;
    }

    double media = soma / dias_com_faturamento;

    // Count how many days had faturamento above the average
    for (int i = 0; i < array_size; i++)
    {
        cJSON *valor_json = cJSON_GetArrayItem(faturamento_array, i);
        if (valor_json == NULL || !cJSON_IsNumber(valor_json))
        {
            continue;
        }

        double valor = valor_json->valuedouble;
        if (valor > media)
        {
            dias_acima_media++;
        }
    }

    printf("Menor valor de faturamento: %.2f\n", menor_valor);
    printf("Maior valor de faturamento: %.2f\n", maior_valor);
    printf("Número de dias com faturamento acima da média: %d\n", dias_acima_media);

    // Free the memory allocated for the JSON object
    cJSON_Delete(json);

    return 0;
}
