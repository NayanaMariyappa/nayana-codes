#include <linux/kernel.h>
#include <linux/modules.h>
#include <linux/init.h>
#include <linux/interrupt.h>

#define DEMO_SOFTIRQ = 23;

static void demo_softirq_handler(struct softirq_action *action)
{
    pr_info("Softirq handler is invoked.\n");
}

static int __init init_demo_softirq(void)
{
    open_softirq(DEMO_SOFTIRQ, demo_softirq_handler);
    raise_softirq(DEMO_SOFTIRQ);
    return 0;
}

static void __exit exit_demo_softirq(void)
{
    pr_info("[Exit] Returning.\n");
}

module_init(init_demo_softirq);
module_exit(exit_demo_softirq);

MODULE_DESCRIPTION("Demo softirq");
MODULE_AUTHOR("Nayana Mariyappa");
MODULE_LICENSE("GPL");