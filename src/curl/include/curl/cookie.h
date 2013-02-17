#ifndef __CURL_COOKIE_H
#define __CURL_COOKIE_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2011, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

#ifdef  __cplusplus
extern "C" {
#endif

struct Cookie {
  struct Cookie *next; /* next in the chain */
  char *name;        /* <this> = value */
  char *value;       /* name = <this> */
  char *path;         /* path = <this> */
  char *domain;      /* domain = <this> */
  curl_off_t expires;  /* expires = <this> */
  char *expirestr;   /* the plain text version */
  bool tailmatch;    /* weather we do tail-matchning of the domain name */

  /* RFC 2109 keywords. Version=1 means 2109-compliant cookie sending */
  char *version;     /* Version = <value> */
  char *maxage;      /* Max-Age = <value> */

  bool secure;       /* whether the 'secure' keyword was used */
  bool livecookie;   /* updated from a server, not a stored file */
  bool httponly;     /* true if the httponly directive is present */
};

CURL_EXTERN struct Cookie *curl_ext_cookie_getlist(CURL *curl, 
												   const char *host, 
												   const char *path, 
												   bool secure);

CURL_EXTERN struct Cookie *curl_ext_cookie_add(CURL *curl, bool header, 
										char *lineptr, 
										const char *domain, 
										const char *path);

CURL_EXTERN void curl_ext_cookie_freelist(struct Cookie *cookies, bool cookiestoo);

CURL_EXTERN void curl_ext_cookie_clearall(CURL *curl);

CURL_EXTERN void curl_ext_cookie_clearsess(CURL *curl);

#ifdef  __cplusplus
}
#endif

#endif /* __CURL_COOKIE_H */
