#include<linux/init.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>

#include<chr_driver.h>


#define COUNT 3
#define BASEMINOR 0
#define NAME "demo_driver"

cdev *cdevp_demo = NULL;
dev_t dev_demo;



int demo_open (struct inode *, struct file *){return 0;}
ssize_t demo_read (struct file *, char __user *, size_t, loff_t *){return 0;}
ssize_t demo_write (struct file *, const char __user *, size_t, loff_t *){return 0;}
int demo_release (struct inode *, struct file *){return 0;}
int demo_ioctl (struct inode *, struct file *, unsigned int, unsigned long){return 0;}

struct file_operations fops_demo={
	.owner = THIS_MODULE,
	.open = demo_open,
	.read = demo_read,
	.write = demo_write,
	.release = demo_release,
	.ioctl = demo_ioctl
};




int dmeo_init(void)
{	
	int ret_dev;
	int major_demo;
	int ret_cdev;

	
/*为设备号分配空间*/
	ret = alloc_chrdev_region( &dev_demo,  BASEMINOR,  COUNT, NAME);
	/*获取设备号失败*/
	if(ret <0)
	{
		printk(KERN_ERR "alloc_chrdev_region failed ...\n");
		goto err1;
	}
/*获取主设备号*/
	major_demo = MAJOR(dev_demo);

/*为cdev分配空闲*/
	cdev_pointer = cdev_alloc(void);
	/*分配空间失败*/
	if(cdev_pointer == NULL)
	{
		printk(KERN_ERR "cdev_pointer failed ...\n");
		goto err2;
	}

/*将cdev结构体 与 file_operation 关联*/
	cdev_init(&cdevp_demo, fops_demo);

/*将cdev结构体与设备号关联*/
	ret_cdev = cdev_add(&cdev_pointer,    dev_demo,  COUNT);

	/*linux添加失败*/
	if(ret_cdev < 0)
	{
		printk(KERN_ERR "alloc_chrdev_region failed ...\n");
		goto err2;
	}
	return 0;


/*注销设备号*/
	err2: unregister_chrdev_region( major_demo,  COUNT);
	err1: return -1;
}






void demo_exit(void)
{
	
/*删除cdev结构体*/
	cdev_del(cdevp_demo);
/*注销设备号*/
	unregister_chrdev_region( major_demo,  COUNT);
}

module_init(dmeo_init);
module_exit(demo_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("lee_young");
