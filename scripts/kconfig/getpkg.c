
#include "lkc.h"
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <signal.h>
#include <unistd.h>
#include "pkg_conf.h"

#include "lkc.h"
#include "lxdialog/dialog.h"
#include "mnconf-common.h"

#include "lxdialog/dialog.h"
#include "mnconf-common.h"

void get_pkg() {
    struct gstr title;
    int dres;
    title = str_new();
    start:
        dialog_clear();
        dres = dialog_inputbox("Search Configuration Parameter",
                    str_get(&title),
                    10, 75, "");
            
            switch(dres){
                case 1:
                    printf("ge");
            }
        

}
