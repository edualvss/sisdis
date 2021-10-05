import pika, os, time

def pdf_process_function(msg):
    print(" Processamento do PDF ")
    print(" [x] Mensagem recebida: "+ str(msg))

    time.sleep(5) # Atraso de 5 segundos
    print(" Processamento do PDF finalizado");
    return;

# Access the CLOUDAMQP_URL environment variable and parse it (fallback to RabbitMQ broker / localhost / cloudamqp
url = os.environ.get('CLOUDAMQP_URL','amqps://tqzvyxix:oGh4wcsnvBrG2U5zzQBDgkcFH_ff8B8C@jackal.rmq.cloudamqp.com/tqzvyxix')
params = pika.URLParameters(url)

connection = pika.BlockingConnection(params)
channel = connection.channel() # Inicia um canal
channel.queue_declare(queue='pdfprocess_aula')

# Função a ser chamada quando uma mensagem chega
def processa_msg(ch,method,properties,body):
    pdf_process_function(body)


# Configura a assinatura (subscribe) na fila
channel.basic_consume('pdfprocess_aula', processa_msg, auto_ack=True)


# Inicia o consumo (blocos)
channel.start_consuming()

connection.close()
