import os
import pwd

def check_credentials():
    print "Current Real UID:       {}".format(os.getuid())
    print "Current Effective UID:  {}".format(os.geteuid())
    print "Current Real GID:       {}".format(os.getgid())
    print "Current Effective GUID: {}".format(os.getegid())

if __name__ == "__main__":
    print "* Before setuid()"
    check_credentials()
    print

    try:
        print "====[ Using the name/UID of your terminal user '{}' ]===="\
              .format(os.getlogin())
        os.setuid(pwd.getpwnam(os.getlogin()).pw_uid)
    except OSError as e:
        print "{} (You need root access to execute this)".format(e)

    print
    print "* After setuid()"
    check_credentials()
