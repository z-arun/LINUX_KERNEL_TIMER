#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/timer.h>
#include<linux/jiffies.h>

static void testfun(struct timer_list * ptr);

struct timer_list tl = {
        .expires  = 0u,
        .function = testfun,
};


static void testfun(struct timer_list * ptr)
{
        pr_info("In timer callback \n");
        mod_timer(&tl,ptr->expires + 7 * HZ);

}


MODULE_LICENSE("GPL");

int __init startFun(void)
{
        printk(KERN_INFO "\nHello world\n");
        //timer_setup(&tl,testfun,0);
        mod_timer(&tl,jiffies + (HZ * 5));
        return 0;
}

void __exit endFun(void)
{
        del_timer(&tl);
        printk(KERN_INFO "\nbye world\n");
}

module_init(startFun);
module_exit(endFun);
