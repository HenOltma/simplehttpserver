/* 
 * File:   filereader.h
 * Author: jannieyk
 *
 * Created on 4. April 2016, 14:51
 */

#ifndef FILEREADER_H
#define	FILEREADER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

char* docroot;
    
char* getFileType (char* filename);
char* readFile (char* filename, char* path);
void setDocroot (char* root);

#ifdef	__cplusplus
}
#endif

#endif	/* FILEREADER_H */

