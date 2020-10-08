#ifndef CHR_DRIVER_H
#define CHR_DRIVER_H



int demo_open (struct inode *, struct file *);
ssize_t demo_read (struct file *, char __user *, size_t, loff_t *);
ssize_t demo_write (struct file *, const char __user *, size_t, loff_t *);
int demo_release (struct inode *, struct file *);
int demo_ioctl (struct inode *, struct file *, unsigned int, unsigned long);

int dmeo_init(void);
void demo_exit(void);



#endif
