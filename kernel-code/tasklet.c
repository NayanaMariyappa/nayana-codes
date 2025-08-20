#include <linux/modules.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/timer.h>
#include 

static struct tasklet_struct demo_tasklet;
static struct timer_list demo_timer;
static atomic_t count_tasklet_runs = ATOMIC_INIT(0);

static void demo_tasklet_handler(unsigned long data)
{
    atomic_inc(&count_tasklet_runs);
    pr_info("New value after the increment: %d; data: %ld\n", atomic_read(count_tasklet_runs), data);
}

static void demo_timer_cb(struct timer_list *t)
{
    tasklet_schedule(&demo_tasklet);
    mod_timer(demo_timer, jiffies + msecs_to_jiffies(5000));
}

static int __init init_demo_tasklet()
{
    /* Create the tasklet */
    tasklet_init(&demo_tasklet, demo_tasklet_handler, 0UL);
    /* Initialize the timer to schedule the tasklet */
    timer_setup(&demo_timer, demo_timer_cb, 0UL);
    mod_timer(&demo_timer, jiffies + msecs_to_jiffies(2000));

    return 0;
}

static void __exit exit_demo_tasklet()
{
    del_timer_sync(&demo_timer); // wait until the callback is finished and then delete.
    tasklet_kill(&demo_tasklet); // wait for tasklet callback to finish before deleting the tasklet.
}

module_init(init_demo_tasklet);
module_exit(exit_demo_tasklet);

MODULE_DESCRIPTION("Demo Tasklets");
MODULE_AUTHOR("Nayana Mariyappa");
MODULE_LICENSE("GPL");