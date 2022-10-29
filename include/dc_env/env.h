#ifndef LIBDC_ENV_ENV_H
#define LIBDC_ENV_ENV_H


/*
 * Copyright 2021-2022 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <dc_error/error.h>
#include <stdbool.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


struct dc_env;

typedef void (*dc_env_tracer)(const struct dc_env *env,
                                const char *file_name,
                                const char *function_name, size_t line_number);

/**
 *
 * @param err
 * @param zero_free
 * @param tracer
 */
struct dc_env *dc_env_create(struct dc_error *err, bool zero_free, dc_env_tracer tracer);

/**
 *
 * @param env
 * @return
 */
bool dc_env_is_zero_free(const struct dc_env *env);

/**
 *
 * @param env
 * @return
 */
dc_env_tracer dc_env_get_tracer(const struct dc_env *env);

/**
 *
 * @param env
 * @param on
 */
void dc_env_set_zero_free(struct dc_env *env, bool on);

/**
 *
 * @param env
 * @param tracer
 */
void dc_env_set_tracer(struct dc_env *env, dc_env_tracer tracer);

/**
 *
 * @param env
 * @param file_name
 * @param function_name
 * @param line_number
 */
void dc_env_default_tracer(const struct dc_env *env, const char *file_name, const char *function_name, size_t line_number);

/**
 *
 * @param env
 * @param file_name
 * @param function_name
 * @param line_number
 */
void dc_env_trace(const struct dc_env *env, const char *file_name, const char *function_name, size_t line_number);


#define DC_TRACE(env) dc_env_trace((env), __FILE__, __func__, __LINE__)


#ifdef __cplusplus
}
#endif


#endif // LIBDC_ENV_ENV_H
