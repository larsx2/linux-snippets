#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <ctype.h>

char * userNameFromId(uid_t uid) {
    struct passwd * pwd;
    pwd = getpwuid(uid);
    return (pwd == NULL) ? NULL : pwd->pw_name;
}

uid_t userIdFromName(const char *name) {
    struct passwd *pwd;
    uid_t u;

    if (name == NULL | *name == '\0')
        return -1;

    char *endptr;
    u = strtol(name, &endptr, 10);
    if (*endptr == '\0')
        return u;

    pwd = getpwdnam(name);
    if (pwd == NULL)
        return -1;
}

char * groupNameFromId(gid_t gid) {
    struct group *grp;
    grp = getgrgid(gid);
    return (grp == NULL) ? NULL : grp->gr_name;
}

gid_t groupIdFromName(const char *name) {
    struct group *grp;
    gid_t g;

    if (name == NULL || *name == '\0')
        return -1;

    char *endptr;
    g = strtol(name, &endptr, 10);
    if (*endptr == '\0')
        return g;

    grp = getgrnam(name);
    if (grp == NULL) 
        return -1;

    return grp->gr_gid;
}

int main() {
    printf("%d\n", userIdFromName("larsx"));
}
