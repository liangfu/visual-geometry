/**
 * @file   common.h
 * @author Liangfu Chen <chenclf@gmail.com>
 * @date   Thu Jun 28 22:04:54 2012
 * 
 * @brief  
 * 
 * 
 */

#ifndef __COMMON_H__
#define __COMMON_H__

#define APPLICATION_TITLE "Visual Geometry"

#define NOTIFY(format, args...)						\
	fprintf(stderr, "%s: %d: note: %s: "format"\n",	\
			__FILE__, __LINE__, #args, args)

#endif //__COMMON_H__
