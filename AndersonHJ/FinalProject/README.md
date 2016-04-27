#Hardware Statement
```
Instance type : t2.micro
vCPUs : 1
Memory : 1GB
Storage : 8GB general purpose SSD
Network interfaces : eth0 
Operating System : Ubuntu Server 14.04 LTS (HVM), SSD Volume Type  64-bit
```

#System Software Statement
```
Operating System : Ubuntu Server 14.04 LTS (HVM), SSD Volume Type  64-bit
Web server : Apache2  
Database : Mysql 5.6
PHP : Memory_limit 512MB
phpmyadmin
```

##LAMP
LAMP is an archetypal model of web service solution stacks, named as an acronym of the names of its original four open-source 
components: the Linux operating system, the Apache HTTP Server, the MySQL relational database management system (RDBMS), and the PHP. 
The LAMP components are largely interchangeable and not limited to the original selection. As a solution stack, LAMP is suitable 
for building dynamic web sites and web applications.

###1. Launch a VM: 
Because our website is just in the beginning, we choose t2.mirco. Just login to aws.amazon.com, sign in to the console, choose EC2 service, click "Launch instance", and choose ubuntu. Although there is no significantly difference between those servers, load balancer and database server, we have make a plan in our future usage. We will use t2.xlarge model as the load balancer, with the configuration:vCPU 4, Mem 30.5GiB, storage 800 SSD. For the database server, we choose d2.xlarge model, with the configuration: vCPU 4, Mem 30.5, Storage 3*2000 HDD. 

###2. Config a VW: Install Linux, Apache, MySQL, PHP (LAMP) stack on Ubuntu
###Step 1: Install Apache
We can install Apache easily using Ubuntu's package manager, apt. For our purposes, we can get started by typing these commands:

    sudo apt-get update
    sudo apt-get install apache2

You can do a spot check right away to verify that everything went as planned by visiting your server's public IP address in your web 
browser :

    http://your_server_IP_address

You will see the default Ubuntu 14.04 Apache web page.If you see that page, then your web server is now correctly installed.

####Configure Load Balancer
And if we want to configure the apache http server to a load balancer. To set up our load-balancer, we use the Apache web-server and its modules mod_proxy, mod_proxy_ajp and mod_proxy_balancer. These are part of most of the Apache web-server distributions.

    <Proxy "balancer://mycluster">
        BalancerMember "http://your_server_IP_address"
        BalancerMember "http://your_server_IP_address"
    </Proxy>
    <VirtualHost *:80>
        ProxyRequests off
        ProxyPass "/test" "balancer://mycluster"
        ProxyPassReverse "/test" "balancer://mycluster"
    </VirtualHost>

###Step 2: Install MySQL
MySQL is a database management system. Basically, it will organize and provide access to databases where our site can store information. Again, we can use apt to acquire and install our software. 

    sudo apt-get install mysql-server php5-mysql

Note: In this case, you do not have to run sudo apt-get update prior to the command. This is because we recently ran it in the commands above to install Apache. During the installation, your server will ask you to select and confirm a password for the MySQL "root" user. When the installation is complete, we need to run some additional commands to get our MySQL environment set up securely.
First, we need to tell MySQL to create its database directory structure where it will store its information. You can do this by 
typing:

    sudo mysql_install_db

Afterwards, we want to run a simple security script that will remove some dangerous defaults and lock down access to our database 
system a little bit. Start the interactive script by running:  

    sudo mysql_secure_installation

You will be asked to enter the password you set for the MySQL root account. Next, it will ask you if you want to change that password.
For the rest of the questions, you should simply hit the "ENTER" key through each prompt to accept the default values. This will remove some sample users and databases, disable remote root logins, and load these new rules so that MySQL immediately 
respects the changes we have made. At this point, your database system is now set up and we can move on.

###Step 3: Install PHP
PHP is the component of our setup that will process code to display dynamic content. It can run scripts, connect to our MySQL databases to get information, and hand the processed content over to our web server to display.We can once again leverage the apt system to install our components.  

    sudo apt-get install php5 libapache2-mod-php5 php5-mcrypt

This should install PHP without any problems. In most cases, we'll want to modify the way that Apache serves files when a directory 
is requested. After this, we need to restart the Apache web server in order for our changes to be recognized. You can do this by 
typing this:

    sudo service apache2 restart

####Install PHP Modules
To enhance the functionality of PHP, we can optionally install some additional modules.If you decide you would like to install a package, you can do so by using the apt-get install command like we have been doing for our other software. If we decided that php5-cli is something that we need, we could type:

    sudo apt-get install php5-cli

If you want to install more than one module, you can do that by listing each one, separated by a space, following the apt-get install 
command, like this:

    sudo apt-get install package1 package2 ...

At this point, your LAMP stack is installed and configured. We should still test out our PHP though.Now that you have a LAMP stack 
installed, you have many choices for what to do next. Basically, you've installed a platform that will allow you to install most 
kinds of websites and web software on your server.


###Install and Secure phpMyAdmin on Ubuntu
####About phpMyAdmin
phpMyAdmin is an free web software to work with MySQL on the web—it provides a convenient visual front end to the MySQL capabilities.
####Install phpMyAdmin
The easiest way to install phpmyadmin is :

    sudo apt-get install phpmyadmin apache2-utils

During the installation, phpMyAdmin will walk you through a basic configuration. After the installation has completed, add phpmyadmin to the apache configuration.

    sudo nano /etc/apache2/apache2.conf

Add the phpmyadmin config to the file.

    Include /etc/phpmyadmin/apache.conf

Restart apache:

    sudo service apache2 restart

You can then access phpmyadmin by going to youripaddress/phpmyadmin. 

####Accessing phpMyAdmin
phpMyAdmin will now be much more secure since only authorized users will be able to reach the login page. Fill it in with the username and password that you generated. After you login you can access phpmyadmin with the MySQL username and password.

#MAGENTO 

Magento is an open eCommerce solution that gives developers complete code visibility and small businesses an affordable way to create 
unique and engaging sites. It is supported by a vibrant community of developers and partners who continually advance the platform by 
contributing code, creating new extensions, and participating in Magento forums and user groups.

##Install and Configure Magento on Ubuntu 
###Step 1 — Configure Apache and PHP
Before we install Magento, Apache and PHP need to be configured to properly handle Magento's traffic and computing tasks, and some 
additional modules will need to be installed and activated.

####Apache Virtual Host
First, we need to configure a virtual host file so that Apache knows how to manage our Magento site correctly. We can use our text 
editor to create a new virtual host file in /etc/apache2/sites-available/. 

    sudo nano /etc/apache2/sites-available/magento.conf

Magento's virtual host needs are fairly simple. Begin with a <VirtualHost> tag that listens for all traffic from port 80, the standard HTTP port. We need to add some additional parameters for Magento to work properly. Inside of a <Directory> tag pointing to our 
document root, we'll enter the options for Apache's directory indexing, symlink support, and multilingual support. We'll also add a 
line that allows .htaccess files to override Apache settings, which provides more fine-grained control of individual folders.

    <Directory /var/www/html/>
        Options Indexes FollowSymLinks MultiViews
        AllowOverride All
    </Directory>
    
When you're finished writing up the server block, save and close the file. To enable the new site with Apache, use the a2ensite command:

    sudo a2ensite magento.conf

We also want to disable the default virtual host that came with Apache, as it will conflict with our new virtual host. To disable a 
site with Apache, use the a2dissite command:

    sudo a2dissite 000-default.conf

####PHP Settings
Next, we need to change how much memory Apache grants to PHP processes. Magento uses PHP for nearly everything it does, and needs a 
decent amount of memory for complex operations like indexing products and categories. By default, PHP allocates a maximum of 128MB of
memory to each script running on Apache. We should bump that limit up to a reasonable amount to ensure that none of Magento's scripts 
run out of memory, which would cause the script to crash. Open Apache's PHP configuration file with your text editor and root privileges:

    sudo nano /etc/php5/apache2/php.ini

Change that line so that the limit is raised to 512MB. Your store's memory needs may be higher depending on the number of products in 
your catalog and the number of visitors you receive daily. Some larger stores need to set their memory limit to 2GB or more, but 512MB should be adequate for now.

    memory_limit = 512M

Magento needs a couple of PHP modules in addition to the ones that come with PHP. We can get these directly from Ubuntu's default 
repositories after we update our local package index:

    sudo apt-get update
    sudo apt-get install libcurl3 php5-curl php5-gd php5-mcrypt

Once all of these configuration and extension changes have been made, it's time to restart the Apache server instance so that the 
changes are applied:

    sudo service apache2 restart

###Step 2 — Create a MySQL Database and User
Magento uses a MySQL database to manage site data, like product and order information. We have MySQL installed and configured, but we 
need to make a database and a user for Magento to work with. Begin by logging into the MySQL root account:

    mysql -u root -p

You will be prompted for MySQL's root account password, which you set when you installed MySQL. Once the correct password has been 
submitted, you will be given a MySQL command prompt. First, we'll create a database that Magento can write data to.

    CREATE DATABASE magento

Next, we are going to create a new MySQL user account that will be used exclusively to operate on the new database. 
You should definitely use a different username and password, as these examples are not very secure.

    CREATE USER magentouser@localhost IDENTIFIED BY 'password'

At this point, you have a database and a user account that are each specifically made for Magento. However, the user has no access 
rights to the database. We need to link the two components together by granting our user access privileges to the database:

    GRANT ALL PRIVILEGES ON magento TO magentouser@localhost IDENTIFIED BY 'password'

Now that the user has access to the database, we need to flush the privileges so that MySQL knows about the recent privilege changes 
that we've made. 

    FLUSH PRIVILEGES

###Step 3 — Download and Set Up Magento Files
We are now ready to download and install Magento. Use wget to download the Magento file archive to your home directory:

    Wget http://www.magentocommerce.com/downloads/assets/magento.tar.gz

We can extract the archived files to rebuild the Magento directory with tar:

    tar xzvf magento.tar.gz

You will now have a directory called magento in your home directory. We'll need to move the unpacked files to Apache's document root, 
where it can be served to visitors of our website. 

    sudo rsync -avP /home/username/magento/. /var/www/html/
    rm -rf home/username/magento*

Now we need to assign ownership of the files and folders to Apache's user and group:

    sudo chown -R www-data:www-data /var/www/html/

This change will allow Apache to create and modify Magento files. We are now ready to complete the installation process via Magento's 
browser-based configuration interface.

###Step 4 — Completing Installation Through the Web Interface
To access the web interface with your browser, navigate to your server's domain name or public IP address:

    http://server_domain_name_or_IP/

You can also visit your new admin site by going to the admin directory that you set previously:

    http://server_domain_name_or_IP/admin/

Log in with your admin username and password to see your new dashboard.
Now that you have your Magento store up and running, you are ready to begin building your project catalog and start selling!

##Github
###push file
```
git add filename

git commit -m "commit name"

git push origin master
```
###download project
```
git config --global user.name "AndersonHJ"

git config --global user.email "hou.jia@husky.neu.edu"

git clone https://github.com/CSYE6225/UnixSysProgramming.git

cd UnixSysProgramming/AndersonHJ/FinalProject

```
###pull files
```
git pull
```
    
    


