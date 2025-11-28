using System;

namespace ClassesDemo
{
    class Website
    {
        private string name;
        private string path;
        private string description;
        private string ipAddress;
        public Website()
        {
            name = "";
            path = "";
            description = "";
            ipAddress = "";
        }

        public Website(string name, string path, string description, string ipAddress)
        {
            this.name = name;
            this.path = path;
            this.description = description;
            this.ipAddress = ipAddress;
        }

        // Метод для введення даних
        public void InputData()
        {
            Console.WriteLine("\n=== Введення даних веб-сайту ===");
            Console.Write("Введіть назву сайту: ");
            name = Console.ReadLine();
            Console.Write("Введіть шлях до сайту (URL): ");
            path = Console.ReadLine();
            Console.Write("Введіть опис сайту: ");
            description = Console.ReadLine();
            Console.Write("Введіть IP-адресу сайту: ");
            ipAddress = Console.ReadLine();
        }
        public void DisplayData()
        {
            Console.WriteLine("\n=== Інформація про веб-сайт ===");
            Console.WriteLine($"Назва: {name}");
            Console.WriteLine($"Шлях: {path}");
            Console.WriteLine($"Опис: {description}");
            Console.WriteLine($"IP-адреса: {ipAddress}");
            Console.WriteLine("================================");
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public string Path
        {
            get { return path; }
            set { path = value; }
        }

        public string Description
        {
            get { return description; }
            set { description = value; }
        }

        public string IpAddress
        {
            get { return ipAddress; }
            set { ipAddress = value; }
        }
    }
    class Magazine
    {
        private string name;
        private int foundationYear;
        private string description;
        private string phone;
        private string email;
        public Magazine()
        {
            name = "";
            foundationYear = 0;
            description = "";
            phone = "";
            email = "";
        }
        public Magazine(string name, int foundationYear, string description, string phone, string email)
        {
            this.name = name;
            this.foundationYear = foundationYear;
            this.description = description;
            this.phone = phone;
            this.email = email;
        }

        public void InputData()
        {
            Console.WriteLine("\n=== Введення даних журналу ===");
            Console.Write("Введіть назву журналу: ");
            name = Console.ReadLine();
            Console.Write("Введіть рік заснування: ");
            foundationYear = int.Parse(Console.ReadLine());
            Console.Write("Введіть опис журналу: ");
            description = Console.ReadLine();
            Console.Write("Введіть контактний телефон: ");
            phone = Console.ReadLine();
            Console.Write("Введіть контактний email: ");
            email = Console.ReadLine();
        }

        public void DisplayData()
        {
            Console.WriteLine("\n=== Інформація про журнал ===");
            Console.WriteLine($"Назва: {name}");
            Console.WriteLine($"Рік заснування: {foundationYear}");
            Console.WriteLine($"Опис: {description}");
            Console.WriteLine($"Телефон: {phone}");
            Console.WriteLine($"Email: {email}");
            Console.WriteLine("==============================");
        }

        // Властивості для доступу до полів
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public int FoundationYear
        {
            get { return foundationYear; }
            set { foundationYear = value; }
        }

        public string Description
        {
            get { return description; }
            set { description = value; }
        }

        public string Phone
        {
            get { return phone; }
            set { phone = value; }
        }

        public string Email
        {
            get { return email; }
            set { email = value; }
        }
    }

    class Shop
    {
        private string name;
        private string address;
        private string profile;
        private string phone;
        private string email;

        public Shop()
        {
            name = "";
            address = "";
            profile = "";
            phone = "";
            email = "";
        }
        public Shop(string name, string address, string profile, string phone, string email)
        {
            this.name = name;
            this.address = address;
            this.profile = profile;
            this.phone = phone;
            this.email = email;
        }

        // Метод для введення даних
        public void InputData()
        {
            Console.WriteLine("\n=== Введення даних магазину ===");
            Console.Write("Введіть назву магазину: ");
            name = Console.ReadLine();
            Console.Write("Введіть адресу магазину: ");
            address = Console.ReadLine();
            Console.Write("Введіть опис профілю магазину: ");
            profile = Console.ReadLine();
            Console.Write("Введіть контактний телефон: ");
            phone = Console.ReadLine();
            Console.Write("Введіть контактний email: ");
            email = Console.ReadLine();
        }

        // Метод для виведення даних
        public void DisplayData()
        {
            Console.WriteLine("\n=== Інформація про магазин ===");
            Console.WriteLine($"Назва: {name}");
            Console.WriteLine($"Адреса: {address}");
            Console.WriteLine($"Профіль: {profile}");
            Console.WriteLine($"Телефон: {phone}");
            Console.WriteLine($"Email: {email}");
            Console.WriteLine("===============================");
        }

        // Властивості для доступу до полів
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public string Address
        {
            get { return address; }
            set { address = value; }
        }

        public string Profile
        {
            get { return profile; }
            set { profile = value; }
        }

        public string Phone
        {
            get { return phone; }
            set { phone = value; }
        }

        public string Email
        {
            get { return email; }
            set { email = value; }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Console.WriteLine("=== Демонстрація роботи класів ===\n");
            Console.WriteLine("1. Робота з класом Website:");
            Website site = new Website("Python.org", "https://www.python.org",
                                      "Офіційний сайт мови Python", "151.101.0.223");
            site.DisplayData();
            site.Description = "Офіційний веб-сайт мови програмування Python";
            Console.WriteLine($"\nОновлений опис: {site.Description}");
            Console.WriteLine("\n\n2. Робота з класом Magazine:");
            Magazine magazine = new Magazine("Наука і життя", 1934,
                                           "Науково-популярний журнал",
                                           "+380441234567", "info@sciencelife.ua");
            magazine.DisplayData();
            Console.WriteLine("\n3. Робота з класом Shop:");
            Shop shop = new Shop("ТехноСвіт", "вул. Хрещатик, 1",
                               "Електроніка та побутова техніка",
                               "+380509876543", "contact@technoworld.ua");
            shop.DisplayData();
            Console.WriteLine("\n\nНатисніть будь-яку клавішу для виходу...");
            Console.ReadKey();
        }
    }
}
