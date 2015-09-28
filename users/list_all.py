import pwd
import grp

for user in pwd.getpwall():
    print "User: {}({})".format(user.pw_name, user.pw_uid)

for group in grp.getgrall():
    print "Group: {}({})".format(group.gr_name, group.gr_gid)
