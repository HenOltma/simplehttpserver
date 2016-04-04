#include <string.h>

#include "filereader.h"

int main(int argc, char** argv) {
    
    setDocroot("./");
    
    //readFile("")      HIER WEITERMACHEN
    
    return (EXIT_SUCCESS);
}

char* getFileType (char* filename) {
    
}

char* readFile (char* filename, char* path) {
    FILE * file;
    DIR* dir;
    struct dirent* dirent;
    char* absolutePath;
    
    // Absoluten Pfad zum Directory erstellen
    strcpy(absolutePath, docroot);
    
    strcat(absolutePath, path);
    
    printf(absolutePath);
    // Datei im Pfad suchen
    
    // dir = opendir ();
    
    // Datei öffnen
    
    // Datei lesen
    
    // Inhalt zurückgeben
    return "test";
}

void setDocroot (char* root) {
    docroot = root;
}