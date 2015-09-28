import pwd
import grp

larsx = pwd.getpwnam('larsx')
print larsx

print """
    Name:  {}
    UID:   {}
    Home:  {}
    Shell: {}
""".format(larsx.pw_name, larsx.pw_uid, larsx.pw_dir, larsx.pw_shell)

group = grp.getgrgid(larsx.pw_gid)
print """
    Group: {}
    GID:   {}
""".format(group.gr_name, group.gr_gid)
