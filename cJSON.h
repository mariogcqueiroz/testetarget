#ifndef CJSON_H
#define CJSON_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <limits.h>
#include <float.h>

/* cJSON Types */
#define cJSON_False 0
#define cJSON_True 1
#define cJSON_NULL 2
#define cJSON_Number 3
#define cJSON_String 4
#define cJSON_Array 5
#define cJSON_Object 6

    /* cJSON structure */
    typedef struct cJSON
    {
        struct cJSON *next;
        struct cJSON *prev;
        struct cJSON *child;

        int type;

        char *valuestring;
        int valueint;
        double valuedouble;

        char *string;
    } cJSON;

    /* Functions for creating JSON values */
    cJSON *cJSON_CreateObject(void);
    cJSON *cJSON_CreateArray(void);
    cJSON *cJSON_CreateString(const char *string);
    cJSON *cJSON_CreateNumber(double num);

    /* Functions for adding items to objects/arrays */
    void cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item);
    void cJSON_AddItemToArray(cJSON *array, cJSON *item);

    /* Parse JSON text */
    cJSON *cJSON_Parse(const char *value);

    /* Convert cJSON object to JSON string */
    char *cJSON_Print(cJSON *item);

    /* Get item from JSON object */
    cJSON *cJSON_GetObjectItem(const cJSON *object, const char *string);

    /* Get item from JSON array */
    cJSON *cJSON_GetArrayItem(const cJSON *array, int item);

    /* Get the number of items in a cJSON array */
    int cJSON_GetArraySize(const cJSON *array);

    /* Check item type */
    int cJSON_IsArray(const cJSON *item);
    int cJSON_IsNumber(const cJSON *item);

    /* Delete a cJSON object */
    void cJSON_Delete(cJSON *item);

#ifdef __cplusplus
}
#endif

#endif /* CJSON_H */
