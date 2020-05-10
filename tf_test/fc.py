import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data

mnist = input_data.read_data_sets("./MNIST_data", one_hot=True)
batch_size=100

n_batch =mnist.train.num_examples# / batch_size

x= tf.placeholder(tf.float32, [None, 784])
y= tf.placeholder(tf.float32, [None, 10])
keep_prob=tf. placeholder(tf.float32)

W1 =tf.Variable(tf.truncated_normal([784, 10],stddev= 0.1))
b1 = tf.Variable(tf.zeros([10])+0.1)
L1=tf.nn.tanh(tf.matmul(x,W1)+b1)
#L1_drop =tf.nn.dropout(L1,keep_prob)

# W2 =tf.Variable(tf.truncated_normal([2000, 2000], stddev=0.1))
# b2 = tf.Variable(tf.zeros([2000])+0.1)
# L2=tf.nn.tanh(tf.matmul(L1,W2)+b1)
# L2_drop =tf.nn.dropout(L2,keep_prob)

# W3 =tf.Variable(tf.truncated_normal([2000, 1000], stddev=0.1))
# b3 = tf.Variable(tf.zeros([2000])+0.1)
# L3=tf.nn.tanh(tf.matmul(L2,W3)+b1)
# L3_drop =tf.nn.dropout(L3,keep_prob)

# W4 =tf.Variable(tf.truncated_normal([1000, 1000], stddev=0.1))
# b4 = tf.Variable(tf.zeros([10])+0.1)
#prediction=tf.nn.softmax(tf.matmul(L3_drop,W4)+b4)

#prediction= tf.nn.softmax(tf.matmul(x,W1)+b)
loss = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=y, logits= L1))

train_step= tf.train.GradientDescentOptimizer(0.2).minimize(loss)

init = tf.global_variables_initializer()

correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax (L1, 1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

with tf.Session() as sess:
    sess.run(init)
    for epoch in range(201):
        #for batch in range(int(n_batch)):
        batch_xs,batch_ys=mnist.train.next_batch(batch_size)
        sess.run(train_step,feed_dict={x:batch_xs,y:batch_ys,keep_prob:1.0})
            
        test_acc=sess.run(accuracy,feed_dict={x:mnist.test.images,y:mnist.test.labels,keep_prob:1.0})
        train_acc=sess.run(accuracy,feed_dict={x:mnist.train.images,y:mnist.train.labels,keep_prob:1.0})
        print("Iter "+str(epoch)+",Testing Accuracy " +str(test_acc)+" trainacc "+str(train_acc))
