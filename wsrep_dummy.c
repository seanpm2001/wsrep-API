/* Copyright (C) 2009 Codership Oy <info@codersihp.com>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*! @file Dummy wsrep API implementation. */
 
#include <errno.h>

#include "wsrep_api.h"

/*! Dummy backend context. */
typedef struct wsrep_dummy
{
    wsrep_log_cb_t log_fn;
} wsrep_dummy_t;

/* Get pointer to wsrep_dummy context from wsrep_t pointer */
#define WSREP_DUMMY(_p) ((wsrep_dummy_t *) (_p)->ctx)

/* Trace function usage a-la DBUG */
#define WSREP_DBUG_ENTER(_w) do {                                       \
        if (WSREP_DUMMY(_w)->log_fn)                                    \
            WSREP_DUMMY(_w)->log_fn(WSREP_LOG_DEBUG, __FUNCTION__);     \
    } while (0)


static void dummy_tear_down(wsrep_t *w)
{
    WSREP_DBUG_ENTER(w);
    free(w->ctx);
    w->ctx = NULL;
}

static wsrep_status_t dummy_init (wsrep_t *w,
                                  const struct wsrep_init_args* args)
{
    WSREP_DUMMY(w)->log_fn = args->logger_cb;
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_enable(wsrep_t *w)
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_disable(wsrep_t *w)
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_recv(wsrep_t *w, void *ctx __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static void dummy_dbug_push(wsrep_t *w,
                            const char *ctrl __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
}

static void dummy_dbug_pop(wsrep_t *w)
{
    WSREP_DBUG_ENTER(w);
}

static wsrep_status_t dummy_commit(
    wsrep_t *w, 
    const trx_id_t   trx_id    __attribute__((unused)), 
    const conn_id_t  conn_id   __attribute__((unused)), 
    const char      *query     __attribute__((unused)), 
    const size_t     query_len __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_replay_trx(
    wsrep_t *w, 
    const trx_id_t  trx_id  __attribute__((unused)), 
    void           *app_ctx __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_cancel_commit(
    wsrep_t *w, 
    const wsrep_seqno_t bf_seqno __attribute__((unused)), 
    const trx_id_t      trx_id   __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_cancel_slave(
    wsrep_t *w, 
    const wsrep_seqno_t bf_seqno     __attribute__((unused)), 
    const wsrep_seqno_t victim_seqno __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_committed(
    wsrep_t *w, 
    const trx_id_t trx_id __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_rolledback(
    wsrep_t *w, 
    const trx_id_t trx_id __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}


static wsrep_status_t dummy_append_query(
    wsrep_t *w, 
    const trx_id_t  trx_id   __attribute__((unused)), 
    const char     *query    __attribute__((unused)), 
    const time_t    timeval  __attribute__((unused)),
    const uint32_t  randseed __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_append_row_key(
    wsrep_t *w, 
    const trx_id_t       trx_id      __attribute__((unused)), 
    const char          *dbtable     __attribute__((unused)),
    const size_t         dbtable_len __attribute__((unused)),
    const char          *key         __attribute__((unused)), 
    const size_t         key_len     __attribute__((unused)), 
    const wsrep_action_t action      __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}


static wsrep_status_t dummy_set_variable(
    wsrep_t *w, 
    const conn_id_t  conn_id   __attribute__((unused)), 
    const char      *key       __attribute__((unused)), 
    const size_t     key_len   __attribute__((unused)),
    const char      *query     __attribute__((unused)), 
    const size_t     query_len __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_set_database(
    wsrep_t *w, 
    const conn_id_t  conn_id   __attribute__((unused)), 
    const char      *query     __attribute__((unused)), 
    const size_t     query_len __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_to_execute_start(
    wsrep_t *w, 
    const conn_id_t  conn_id   __attribute__((unused)),
    const char      *query     __attribute__((unused)), 
    const size_t     query_len __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_to_execute_end(
    wsrep_t *w,
    const conn_id_t  conn_id   __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_sst_sent(
    wsrep_t *w,
    const wsrep_uuid_t* uuid   __attribute__((unused)),
    wsrep_seqno_t       seqno  __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_status_t dummy_sst_received(
    wsrep_t *w,
    const wsrep_uuid_t* uuid  __attribute__((unused)),
    wsrep_seqno_t       seqno __attribute__((unused)))
{
    WSREP_DBUG_ENTER(w);
    return WSREP_OK;
}

static wsrep_t dummy_iface = {
    WSREP_INTERFACE_VERSION,
    &dummy_init,
    &dummy_enable,
    &dummy_disable,
    &dummy_dbug_push,
    &dummy_dbug_pop,
    &dummy_recv,
    &dummy_commit,
    &dummy_replay_trx,
    &dummy_cancel_commit,
    &dummy_cancel_slave,
    &dummy_committed,
    &dummy_rolledback,
    &dummy_append_query,
    &dummy_append_row_key,
    &dummy_set_variable,
    &dummy_set_database,
    &dummy_to_execute_start,
    &dummy_to_execute_end,
    &dummy_sst_sent,
    &dummy_sst_received,
    &dummy_tear_down,
    NULL,
    NULL
};

int wsrep_dummy_loader(wsrep_t *w)
{
    if (!w)
        return EINVAL;

    *w = dummy_iface;

    // allocate private context
    if (!(w->ctx = malloc(sizeof(wsrep_dummy_t))))
        return ENOMEM;

    // initialize private context
    WSREP_DUMMY(w)->log_fn = NULL;

    return 0;
}

