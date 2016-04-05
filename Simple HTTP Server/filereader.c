#include "filereader.h"

int main(int argc, char** argv) {
    getFileType("example.html");
    
    //readFile("")      HIER WEITERMACHEN
    
    return (EXIT_SUCCESS);
}
/**
 * Gibt die Dateiendung der Datei zurück.
 * Dateiendungen mit Punkten werden nicht unterstützt!
 * Dateinamen, die länger als 255 (CHARBUFF) sind werden nicht unterstützt!
 * @param filename Der Name der Datei
 * @return Die Dateiendung
 */
char* getFileType (const char* filename) {
    char str[CHARBUFF]; 
    const char delimiter[2] = ".";
    char *token;
    
    if (strlen(filename) > CHARBUFF) return;
   
    strcpy(str, filename);
    
    // Erster Abschnitt
    token = strtok(str, delimiter);
   
    // Weitere Abschnitte durchlaufen
    while(token != NULL) {
        printf( " %s\n", token );
    
        token = strtok(NULL, delimiter);
    }
    
    // Dateiendung ist nun in token gespeichert
    return token;
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
