/* This file is automatically generated from rep-cache-db.sql and /opt/svnrm/tempdir/subversion-1.10.0/subversion/libsvn_fs_fs/token-map.h.
 * Do not edit this file -- edit the source and rerun gen-make.py */

#define STMT_CREATE_SCHEMA_V1 0
#define STMT_0_INFO {"STMT_CREATE_SCHEMA_V1", NULL}
#define STMT_0 \
  "CREATE TABLE rep_cache ( " \
  "  hash TEXT NOT NULL PRIMARY KEY, " \
  "  revision INTEGER NOT NULL, " \
  "  offset INTEGER NOT NULL, " \
  "  size INTEGER NOT NULL, " \
  "  expanded_size INTEGER NOT NULL " \
  "  ); " \
  "PRAGMA USER_VERSION = 1; " \
  ""

#define STMT_CREATE_SCHEMA_V2 1
#define STMT_1_INFO {"STMT_CREATE_SCHEMA_V2", NULL}
#define STMT_1 \
  "CREATE TABLE rep_cache ( " \
  "  hash TEXT NOT NULL PRIMARY KEY, " \
  "  revision INTEGER NOT NULL, " \
  "  offset INTEGER NOT NULL, " \
  "  size INTEGER NOT NULL, " \
  "  expanded_size INTEGER NOT NULL " \
  "  ) WITHOUT ROWID; " \
  "PRAGMA USER_VERSION = 2; " \
  ""

#define STMT_GET_REP 2
#define STMT_2_INFO {"STMT_GET_REP", NULL}
#define STMT_2 \
  "SELECT revision, offset, size, expanded_size " \
  "FROM rep_cache " \
  "WHERE hash = ?1 " \
  ""

#define STMT_SET_REP 3
#define STMT_3_INFO {"STMT_SET_REP", NULL}
#define STMT_3 \
  "INSERT OR FAIL INTO rep_cache (hash, revision, offset, size, expanded_size) " \
  "VALUES (?1, ?2, ?3, ?4, ?5) " \
  ""

#define STMT_GET_REPS_FOR_RANGE 4
#define STMT_4_INFO {"STMT_GET_REPS_FOR_RANGE", NULL}
#define STMT_4 \
  "SELECT hash, revision, offset, size, expanded_size " \
  "FROM rep_cache " \
  "WHERE revision >= ?1 AND revision <= ?2 " \
  ""

#define STMT_GET_MAX_REV 5
#define STMT_5_INFO {"STMT_GET_MAX_REV", NULL}
#define STMT_5 \
  "SELECT MAX(revision) " \
  "FROM rep_cache " \
  ""

#define STMT_DEL_REPS_YOUNGER_THAN_REV 6
#define STMT_6_INFO {"STMT_DEL_REPS_YOUNGER_THAN_REV", NULL}
#define STMT_6 \
  "DELETE FROM rep_cache " \
  "WHERE revision > ?1 " \
  ""

#define STMT_LOCK_REP 7
#define STMT_7_INFO {"STMT_LOCK_REP", NULL}
#define STMT_7 \
  "BEGIN TRANSACTION; " \
  "INSERT INTO rep_cache VALUES ('dummy', 0, 0, 0, 0) " \
  ""

#define STMT_UNLOCK_REP 8
#define STMT_8_INFO {"STMT_UNLOCK_REP", NULL}
#define STMT_8 \
  "ROLLBACK TRANSACTION; " \
  ""

#define REP_CACHE_DB_SQL_DECLARE_STATEMENTS(varname) \
  static const char * const varname[] = { \
    STMT_0, \
    STMT_1, \
    STMT_2, \
    STMT_3, \
    STMT_4, \
    STMT_5, \
    STMT_6, \
    STMT_7, \
    STMT_8, \
    NULL \
  }

#define REP_CACHE_DB_SQL_DECLARE_STATEMENT_INFO(varname) \
  static const char * const varname[][2] = { \
    STMT_0_INFO, \
    STMT_1_INFO, \
    STMT_2_INFO, \
    STMT_3_INFO, \
    STMT_4_INFO, \
    STMT_5_INFO, \
    STMT_6_INFO, \
    STMT_7_INFO, \
    STMT_8_INFO, \
    {NULL, NULL} \
  }
